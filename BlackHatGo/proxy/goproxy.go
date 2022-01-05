package main

import (
	"fmt"
	"flag"
	"net/http"
	"net/http/httputil"
	"net/url"
	"errors"
	"github.com/gorilla/mux"
	log "github.com/sirupsen/logrus"
)

var (
	proxies		= make(map[string]*httputil.ReverseProxy)
	proxy *string
	others []string
)

func proxy_init(){
	remote, err := url.Parse(*proxy)
	if (err!=nil){
		log.Errorf("Unable To Parse Proxy Target: %s",err)
	}

	for _,v := range others {
		proxies[v] = httputil.NewSingleHostReverseProxy(remote)
	}
}

func argparse() error {
	proxy = flag.String("p,proxy","","The proxy to forward to")
	flag.Parse()
	others = flag.Args()

	if(*proxy == ""){
		return errors.New("Target proxy needs to be decleared")
	}

	if(len(others) <= 0){
		return errors.New(fmt.Sprintf("Needs more than %d hosts",len(others)))
	}

	return nil
}

func main() {
	err := argparse()
	if err != nil {
		log.Fatal(err)
	}

	proxy_init()

	r := mux.NewRouter()
	for host, proxy := range proxies {
		r.Host(host).Handler(proxy)
	}

	log.Fatal(http.ListenAndServe(":8081",r))
}
