package main

import (
	"os"
	"flag"
	"strings"
	"errors"
	"io/ioutil"
	"github.com/mysteriumnetwork/go-openvpn/openvpn3"
	log "github.com/sirupsen/logrus"
)

var (
	vpn_file *string	
	creds openvpn3.UserCredentials = openvpn3.UserCredentials{}
)

func argparse() error {
	vpn_file = flag.String("vp","","The Vpn file to use")
	flag.StringVar(&creds.Username,"-u","","The username to use")
	flag.StringVar(&creds.Password,"-p","","The password to use")
	flag.Parse()

	if *vpn_file == "" {
		return errors.New("VPN profile is required")
	}
}

func main(){
    log.SetOutput(os.Stdout)

	err := argparse()
	if err != nil {
		log.Error(err)
		return 
	}
 
	openvpn3.SelfCheck(log)

	bytes, err := ioutil.ReadFile(*vpn_file)
	if err != nil {
		log.Error(err)
		return
	}

	config := openvpn3.NewConfig(string(bytes))
	session := openvpn3.NewSession(config, creds, nil)

	session.Start()
	err = session.Wait()
	if err != nil {
		log.Fatal(err)
		return
	}
}
