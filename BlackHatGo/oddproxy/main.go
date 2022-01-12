package main

import (
	"flag"
	"net"
	"net/http"
	"net/http/httputil"
	"net/url"
	"github.com/gorilla/mux"
	log "github.com/sirupsen/logrus"
)

const (
	proto string = "tcp"
)

var (
	connect_host *string
	connect_port *int

	pass_host *string
	pass_port *int

	out_soc net.Socket
	in_soc net.Socket
)

func Init(){
	connect_host = flag.String("ch","localhost","Connect host")
	connect_port = flag.Int("cp",31337,"Connect port")
	pass_host = flag.String("ph","localhost","Pass host")
	pass_port = flag.Int("pp",31337,"Pass port")
 	flag.Parse()
}

func Dail() error {
	out_soc, err = net.Dail(proto, fmt.Sprintf("%s:%d",pass_host,pass_port))
	if err != nil {
		logrus.Errorf("Could not Connect to %s:%d %s",pass_host,pass_port,err)
		return err
	}

	in_soc, err = net.Dail(proto, fmt.Sprintf("%s:%d",connect_host,connect_port))
	if err != nil {
		logrus.Errorf("Could not Connect to %s:%d %s",connect_host,connect_port,err)
		return err
	}
	return nil
}

func main(){}
