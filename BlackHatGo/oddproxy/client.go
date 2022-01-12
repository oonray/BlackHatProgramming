package main

import (
	"flag"
	"net"
	"net/http"
	"net/http/httputil"
	"net/url"
	"github.com/gorilla/mux"
	log "github.com/sirupsen/logrus"
	pki "github.com/oonray/BlackHatProgramming/BlackHatGo/PKI/"
	ssh "golang.org/x/crypto/ssh"
)

const (
	proto string = "tcp"
)

var (
	pki pki.PKI
	lp *string
	pk *string
)

func flags(){
	lp = flag.String("lp","","Listen Port")
}

func main(){

}
