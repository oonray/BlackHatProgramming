package jsonserver

import (
	"net/http"

	rpc "github.com/gorilla/rpc"
	jrpc "github.com/gorilla/rpc/json"
	log "github.com/sirupsen/logrus"

	sqldb "bookdb/sqldb"

	"gorm.io/gorm"
)

type Args struct {
	book sqldb.Book
}

type JSONServer struct {
	Db *gorm.DB
}

func New(db *gorm.DB) (*JSONServer, error) {
	var err error = nil

	server := new(JSONServer)
	server.Db, err = sqldb.New("./test.db")

	if err != nil {
		return nil, err
	}
	return server, nil
}

func (j *JSONServer) GETBook(r *http.Request, args Args, reply *[]sqldb.Book) error {
	var books []sqldb.Book
	j.Db.Find(&books, args.book)
	*reply = books
	return nil
}

func (j *JSONServer) GETBooks(r *http.Request, args Args, reply *[]sqldb.Book) error {
	var books []sqldb.Book
	*reply = books
	return nil
}

func (j *JSONServer) PUTBook(r *http.Request, args Args, _ *[]sqldb.Book) error {
	return j.Db.Create(args.book)
}
