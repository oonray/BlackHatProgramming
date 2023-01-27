package main

import (
	"encoding/json"
	"io/ioutil"
	"net/http"
	"os"

	mux "github.com/gorilla/mux"
	rpc "github.com/gorilla/rpc"
	jrpc "github.com/gorilla/rpc/json"
	log "github.com/sirupsen/logrus"
)

type Args struct {
	Id string
}

type Book struct {
	Id     string `json:string,omitempty`
	Name   string `json:name,omitmepty`
	Author string `json:author, omitempty`
}

type JSONServer struct{}

func (j *JSONServer) GiveBookDetail(r *http.Request, args Args, reply *Book) error {
	var books []Book
	raw, readerr := ioutil.ReadFile("./book.json")
	if readerr != nil {
		log.Errorf("Error with json file, exiting: %s", readerr)
		os.Exit(1)
	}

	marshalerr := json.Unmarshal(raw, &books)
	if marshalerr != nil {
		log.Errorf("Error with json file, exiting: %s", marshalerr)
		os.Exit(1)
	}

	for _, book := range books {
		if book.Id == args.Id {
			*reply = book
		}
		break
	}
	return nil
}

func main() {
	s := rpc.NewServer()
	s.RegisterCodec(jrpc.NewCodec(), "application/json")
	s.RegisterService(new(JSONServer), "")

	r := mux.NewRouter()
	r.Handle("/rpc", s)
	http.ListenAndServe(":8000", r)
}
