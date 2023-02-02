package main

import (
	"net/http"

	//sqldb "bookdb/sqldb"

	mux "github.com/gorilla/mux"
	rpc "github.com/gorilla/rpc"
	jrpc "github.com/gorilla/rpc/json"
	log "github.com/sirupsen/logrus"

	server "bookdb/jsonserver"
)

var srv server.JSONServer

func init() {
	srv, err := server.New("./db.sql")
	if err != nil {
		log.Errorf("Could not init server %s", srv)
		return
	}

	//srv.Db.ADDBook(sqldb.New_Book("Lorem", "Ipsum"))
}

func main() {
	log.Infof("Starting")

	s := rpc.NewServer()
	s.RegisterCodec(jrpc.NewCodec(), "application/json")
	s.RegisterService(srv, "")

	r := mux.NewRouter()
	r.Handle("/rpc", s)

	log.Infof("Starting handler on :8181")
	if err := http.ListenAndServe(":8181", r); err != nil {
		log.Errorf("Could not serve: %s")
	}
}
