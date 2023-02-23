package main

import (
	"encoding/json"
	"fmt"
	"net/http"
	"os"
	"time"

	jwt "github.com/golang-jwt/jwt/v5"
	//mux "github.com/gorilla/mux"
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

	if claims, ok := token.Claims.(jwt.MapClaims); ok && token.Valid {
		response := make(map[string]string)
		response["time"] = time.Now().String()
		response["user"] = claims["username"].(string)
		responseJSON, _ := json.Marshal(response)
		w.Write(responseJSON)
	} else {
		w.WriteHeader(http.StatusForbidden)
		w.Write([]byte("Access Denied"))
		return
	}
}

func getTokenHandler(w http.ResponseWriter, r *http.Request) {

}

func main() {

}
