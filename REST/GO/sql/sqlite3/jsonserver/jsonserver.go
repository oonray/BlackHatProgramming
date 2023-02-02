package jsonserver

import (
	"net/http"

	sqldb "bookdb/sqldb"
)

type Args struct {
	Book sqldb.Book
}

type JSONServer struct {
	Db *sqldb.SQLServer
}

func New(path string) (*JSONServer, error) {
	var err error = nil

	server := new(JSONServer)
	server.Db, err = sqldb.New(path)

	if err != nil {
		return nil, err
	}

	return server, nil
}

func (j *JSONServer) GETBook(r *http.Request, args Args, reply *[]sqldb.Book) error {
	reply = j.Db.GetBookAuthor(&args.Book.Author)
	return nil
}

func (j *JSONServer) GETBooks(r *http.Request, args Args, reply *[]sqldb.Book) error {
	reply = j.Db.GetBooks()
	return nil
}

func (j *JSONServer) PUTBook(r *http.Request, args Args, _ *[]sqldb.Book) error {
	j.Db.ADDBook(&args.Book)
	return nil
}
