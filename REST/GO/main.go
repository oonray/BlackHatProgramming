package main

import (
	"encoding/json"
	"net/http"
	"os"
	"time"

	handlers "github.com/gorilla/handlers"
	mux "github.com/gorilla/mux"
	"github.com/justinas/alice"
	log "github.com/sirupsen/logrus"
	md "rest/middleware"
)

const Listen string = "127.0.0.1:8000"

var R *mux.Router

type City struct {
	Name string `json:"name"`
	Area uint64 `json:"m2"`
}

func mainLogic(w http.ResponseWriter, r *http.Request) {
	if r.Method == "POST" {
		var tmp City
		decoder := json.NewDecoder(r.Body)

		err := decoder.Decode(&tmp)
		if err != nil {
			w.WriteHeader(500)
			return
		}

		defer r.Body.Close()

		log.Infof("We got %s with an aerea of %d km2", tmp.Name, tmp.Area)

		w.WriteHeader(http.StatusCreated)
		w.Write([]byte("201 - Created"))
		return
	}
	w.WriteHeader(http.StatusMethodNotAllowed)
	w.Write([]byte("405 - Meethod Not Allowed"))
	return
}

func main() {
	router := mux.NewRouter()

	loggedRouter := handlers.LoggingHandler(os.Stdout, router)

	mainHandler := http.HandlerFunc(mainLogic)
	chain := alice.New(md.FilterContentType, md.SetServerTimeCookie, md.Middleware).Then(mainHandler)

	router.Handle("/city", chain)

	srv := &http.Server{
		Addr:         Listen,
		Handler:      loggedRouter,
		WriteTimeout: 15 * time.Second,
		ReadTimeout:  15 * time.Second,
	}

	log.Infof("Listening on %s", Listen)
	log.Fatal(srv.ListenAndServe())
}
