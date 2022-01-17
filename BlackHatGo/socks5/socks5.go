package main

import (
	"fmt"
	"flag"
	"net/http"
	"net/http/httputil"
	"net/url"
	"errors"
	"github.com/gorilla/mux"
    "github.com/things-go/go-socks5"
	log "github.com/sirupsen/logrus"
)

var (
	lp *string
)

func argparse(){
	lp = flag.String("lp","","Port to listen to")
	flag.Parse()
}

func main() {
	server := socks5.NewServer(
		socks5.WithLogger(
			log.New(),
		),
	)

	if err := server.ListenAndServe("tcp",fmt.Sprintf(":%s",lp));err != nil {
		log.Fatalf("%s",err)
	}
}
