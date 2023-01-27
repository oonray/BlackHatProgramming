package main

import (
	"context"
	"log"

	rpc "github.com/ybbus/jsonrpc/v3"
)

type Args struct {
	Book Book
}

type Book struct {
	Id     string `json:string, omitempty`
	Name   string `json:name, omitmepty`
	Author string `json:author, omitempty`
}

func main() {
	s := rpc.NewClient("http://localhost:8181/rpc")

	response, err := s.Call(context.Background(), "GetBooks")
	if err != nil {
		log.Fatalf("Could not call GetBooks %s %v", err, response)
		return
	}
}
