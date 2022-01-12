package main

import (
	"net/http"
	"net/http/httputil"
	"net/url"
	"github.com/gorilla/mux"
	log "github.com/sirupsen/logrus"
)

var (
	hostProxy 	= make(map[string]string)
	proxies		= make(map[string]*httputil.ReverseProxy)
)

func init(){
	hostProxy["attacker1.com"] = "http://10.0.1.20:10080"
	hostProxy["attacker2.com"] = "http://10.0.1.20:20080"
	for k,v := range hostProxy {
		remote, err := url.Parse(v)
		if (err!=nil){
			log.Fatalf("Unable To Parse Proxy Target")
		}
		proxies[k] = httputil.NewSingleHostReverseProxy(remote)
	}
}

func main() {
	r = mux.NewRouter()
	for host, proxy := range proxies {
		r.Host(host).Handler(proxy)
	}
	log.Fatal(http.ListenAndServe(":80",r))

}
