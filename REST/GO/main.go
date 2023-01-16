package main

import (
	"fmt"
	"net/http"
	"time"

	mux "github.com/gorilla/mux"
	log "github.com/sirupsen/logrus"
)

const Listen string = "127.0.0.1:8000"

var R *mux.Router

func middleware(handler http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		fmt.Println("Executing middleware before")
		handler.ServeHTTP(w, r)
		fmt.Println("Executing middleware after")
	})
}

func main() {
	srv := &http.Server{
		Addr:         Listen,
		Handler:      R,
		WriteTimeout: 15 * time.Second,
		ReadTimeout:  15 * time.Second,
	}

	log.Infof("Listening on %s", Listen)
	log.Fatal(srv.ListenAndServe())
}
