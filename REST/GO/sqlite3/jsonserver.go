package main

import (
	"encoding/json"
	"net/http"
	"net/rpc"
	"time"

	rpc "github.com/gorilla/rpc"
	jrpc "github.com/gorilla/rpc/json"
	log "github.com/sirupsen/logrus"

	"gorm.io/driver/sqlite"
	"gorm.io/gorm"
)

type JSONServer struct {
	Db *gorm.DB
}

func NewJsonServer(db *gorm.DB) (*JSONServer, error) {
	var err error = nil

	server := new(JSONServer)
	server.Db, err = NewSQLServer("./test.db")

	if err != nil {
		return nil, err
	}
	return server, nil
}

func (j *JSONServer) GETBook(r *http.Request, args Args, reply *[]Book) error {
	var books []Book
	j.Db.Find(&books, args.book)
	*reply = books
	return nil
}

func (j *JSONServer) GETBooks(r *http.Request, args Args, reply *[]Book) error {
	var books []Book
	*reply = books
	return nil
}

func (j *JSONServer) PUTBook(r *http.Request, args Args, _ *[]Book) error {
	return j.Db.Create(args.book)
}
