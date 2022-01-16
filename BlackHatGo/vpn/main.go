package main

import (
	"os"
	"flag"
	"errors"
	"io/ioutil"
	"github.com/mysteriumnetwork/go-openvpn/openvpn3"
	log "github.com/sirupsen/logrus"
)

var (
	vpn_file *string	
	creds openvpn3.UserCredentials = openvpn3.UserCredentials{}
)

type callbacks interface {
	openvpn3.Logger
	openvpn3.EventConsumer
	openvpn3.StatsConsumer
}

type loggingCallbacks struct {
}

func (lc *loggingCallbacks) Log(text string) {
	lines := strings.Split(text, "\n")
	for _, line := range lines {
		fmt.Println("Openvpn log >>", line)
	}
}

func (lc *loggingCallbacks) OnEvent(event openvpn3.Event) {
	fmt.Printf("Openvpn event >> %+v\n", event)
}

func (lc *loggingCallbacks) OnStats(stats openvpn3.Statistics) {
	fmt.Printf("Openvpn stats >> %+v\n", stats)
}

var _ callbacks = &loggingCallbacks{}

type StdoutLogger func(text string)

func (lc StdoutLogger) Log(text string) {
	lc(text)
}

func argparse() error {
	vpn_file = flag.String("vp","","The Vpn file to use")
	flag.StringVar(&creds.Username,"u","","The username to use")
	flag.StringVar(&creds.Password,"p","","The password to use")
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

	var logger StdoutLogger = func(text string) {
		lines := strings.Split(text, "\n")
		for _, line := range lines {
			fmt.Println("Library check >>", line)
		}
	}

	openvpn3.SelfCheck(logger)
 
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
