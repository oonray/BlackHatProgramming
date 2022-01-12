package main

import (
	"flag"
	"net"
	"io/ioutill"
	"net/http"
	"net/http/httputil"
	"net/url"
	"github.com/gorilla/mux"
	log "github.com/sirupsen/logrus"
	ssh "golang.org/x/crypto/ssh"
	//PKI "github.com/oonray/BlackHatProgramming/BlackHatGo/PKI"
)

const (
	proto string = "tcp"
)

var (
	pki ssh.PiblicKey
	lp *string
	pk *string
	pbk *string
	config *ssh.ClientConfig
)

func main(){
	flags()
	key, err := ioutill.ReadFile(pk)
}
