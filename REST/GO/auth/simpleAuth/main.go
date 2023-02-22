package main

import (
	mux "github.com/gorilla/mux"
	sessions "github.com/gorilla/sessions"
	"log"
	"net/http"
	"os"
	"time"
)

var (
	store = sessions.NewCookieStore([]byte(os.Getenv("SESSION_SECRET")))
	users = map[string]string{"naren": "passme", "admin": "password"}
)

func HealthcheckHandler(w http.ResponseWriter, r *http.Request) {
	session, _ := store.Get(r, "session.id")
	if session.Values["authenticated"] != nil && session.Values["authenticated"] != false {
		w.Write([]byte(time.Now().String()))
	} else {
		http.Error(w, "Forbidden", http.StatusForbidden)
	}
}

func LoginHandler(w http.ResponseWriter, r *http.Request) {
	session, _ := store.Get(r, "session.id")
	err := r.ParseForm()
	if err != nil {
		http.Error(w, "Please pass data as url form encoded", http.StatusBadRequest)
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

	session.Values["authenticated"] = true
	session.Save(r, w)

	w.Write([]byte("Logged In Successfully"))
}

func LogoutHandler(w http.ResponseWriter, r *http.Request) {
	session, _ := store.Get(r, "session.id")
	session.Values["authenticated"] = false
	session.Save(r, w)
	w.Write([]byte(""))
}

func main() {
	r := mux.NewRouter()
	r.HandleFunc("/login", LoginHandler)
	r.HandleFunc("/healthcheck", HealthcheckHandler)
	r.HandleFunc("/logout", LogoutHandler)
	http.Handle("/", r)

	srv := &http.Server{
		Handler:      r,
		Addr:         "127.0.0.1:8000",
		WriteTimeout: 15 * time.Second,
		ReadTimeout:  15 * time.Second,
	}

	log.Fatal(srv.ListenAndServe())
}
