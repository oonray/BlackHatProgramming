package main

import (
	"os"
	"flag"
	"errors"
	"io/ioutil"
	openvpn "github.com/lighthouse8/go-openvpn"
	log "github.com/sirupsen/logrus"
)

var (
	vpn_file *string
	config *openvpn.Config
)

func argparse() error {
	vpn_file = flag.String("vp","","The Vpn file to use")
	flag.Parse()

	if *vpn_file == "" {
		return errors.New("VPN profile is required")
	}
	return nil
}

func main(){
    log.SetOutput(os.Stdout)

	err := argparse()
	if err != nil {
		log.Error(err)
		return 
	}

	config = config.NewConfig()
	config.LoadFile(*vpn_file)

}
