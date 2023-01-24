package main

import (
	"net/http"

	mux "github.com/gorilla/mux"
	jrpc "github.com/gorilla/rpc/json"
	log "github.com/sirupsen/logrus"

	server "bookdb/jsonserver"
)

func main() {
	log.Infof("Starting")
	s := jrpc.NewServer()
	s.RegisterCodec(jrpc.NewCodec(), "application/json")
	s.RegisterService(new(server.JSONServer), "")

	r := mux.NewRouter()
	r.Handle("/rpc", s)

	log.Infof("Starting handler on :8181")
	if err := http.ListenAndServe(":8181", r); err != nil {
		log.Errorf("Could not serve: %s")
	}
}
