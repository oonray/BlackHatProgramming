package main

import (
	"fmt"
	"flag"
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
	server := socks5.NewServer()

	if err := server.ListenAndServe("tcp",fmt.Sprintf(":%s",*lp));err != nil {
		log.Fatalf("%s",err)
	}
}

//uh
