package main

import (
	"os"
	"log"
	"fmt"
	"flag"
    "github.com/things-go/go-socks5"
	logR "github.com/sirupsen/logrus"
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
		socks5.WithLogger(socks5.NewLogger(log.New(os.Stdout, "socks5: ", log.LstdFlags))),
	)

	if err := server.ListenAndServe("tcp",fmt.Sprintf(":%s",*lp));err != nil {
		logR.Fatalf("%s",err)
	}
}

//uh
