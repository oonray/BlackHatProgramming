package main

import (
	"encoding/json"
	"net/http"
	"net/rpc"
	"time"

	mux "github.com/gorilla/mux"
	rpc "github.com/gorilla/rpc"
	jrpc "github.com/gorilla/rpc/json"
	log "github.com/sirupsen/logrus"

	"gorm.io/driver/sqlite"
	"gorm.io/gorm"
)

type Args struct {
	book Book
}

type Book struct {
	Id     string `json:string,omitempty`
	Name   string `json:name,omitmepty`
	Author string `json:author, omitempty`
}

func main() {
	s := jrpc.NewServer()
	s.RegisterCodec(jrpc.NewCodec(), "application/json")
	s.RegisterService(new(JSONServer), "")

	r := mux.NewRouter()
	r.Handle("/rpc", s)

	log.Infof("Starting handler on :8181")
	if err := http.ListenAndServe(":8181", r); err != nil {
		log.Errorf("Could not serve: %s")
	}
}
