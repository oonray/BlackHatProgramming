package main

import (
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	"os"
	"time"

	jwt "github.com/golang-jwt/jwt/v5"
	mux "github.com/gorilla/mux"
)

var (
	secretKey = []byte(os.Getenv("SESSION_SECRET"))
	users     = map[string]string{"naren": "passme", "admin": "password"}
)

type Response struct {
	Token  string `json:"token"`
	Status string `json:"status"`
}

func HealthcheckHandler(w http.ResponseWriter, r *http.Request) {
	token, err := jwt.NewParser().Parse(r.Header.Get("access_token"), func(token *jwt.Token) (interface{}, error) {
		if _, ok := token.Method.(*jwt.SigningMethodHMAC); !ok {
			return nil, fmt.Errorf("Wrong Signing method: %v", token.Header["alg"])
		}
		return secretKey, nil
	})

	if err != nil {
		w.WriteHeader(http.StatusForbidden)
		w.Write([]byte("Access Denied"))
		return
	}

	claims, ok := token.Claims.(jwt.MapClaims)
	if !ok && !token.Valid {
		w.WriteHeader(http.StatusForbidden)
		w.Write([]byte("Access Denied"))
	}

	response := make(map[string]string)
	response["time"] = time.Now().String()
	response["user"] = claims["username"].(string)
	responseJSON, _ := json.Marshal(response)

	w.Write(responseJSON)
}

func getTokenHandler(w http.ResponseWriter, r *http.Request) {
	err := r.ParseForm()
	if err != nil {
		http.Error(w, "Parameters not supported", http.StatusBadRequest)
		return
	}

	username := r.PostForm.Get("username")
	password := r.PostForm.Get("password")

	originalPassword, ok := users[username]

	if !ok {
		http.Error(w, "User is not found", http.StatusNotFound)
		return
	}

	if password != originalPassword {
		http.Error(w, "Invalid Creds", http.StatusUnauthorized)
		return
	}

	claims := jwt.MapClaims{
		"username":  username,
		"ExpiresAt": 15000,
		"IssuedAt":  time.Now().Unix(),
	}

	token := jwt.NewWithClaims(jwt.SigningMethodHS256, claims)
	tokenString, err := token.SignedString(secretKey)
	if err != nil {
		w.WriteHeader(http.StatusBadGateway)
		w.Write([]byte(err.Error()))
	}

	response := Response{Token: tokenString, Status: "success"}
	responseJSON, _ := json.Marshal(response)

	w.WriteHeader(http.StatusOK)
	w.Header().Set("Content-Type", "application/json")
	w.Write(responseJSON)
}

func main() {
	r := mux.NewRouter()
	r.HandleFunc("/getToken", getTokenHandler)
	r.HandleFunc("/healthcheck", HealthcheckHandler)
	http.Handle("/", r)

	srv := &http.Server{
		Handler:      r,
		Addr:         "127.0.0.1:8000",
		WriteTimeout: 15 * time.Second,
		ReadTimeout:  15 * time.Second,
	}

	log.Fatal(srv.ListenAndServe())
}
