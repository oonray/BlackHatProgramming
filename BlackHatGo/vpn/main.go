package main

import (
	"flag"
	"strings"
	"io/ioutill"
	"github.com/mysteriumnetwork/go-openvpn/openvpn3"
	log "github.com/sirupsen/logrus"
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
		log.WithFields(log.Fields{"prog":"openvpn","type":"Log"}).Infof("%s", line)
	}
}

func (lc *loggingCallbacks) OnEvent(event openvpn3.Event) {
		log.WithFields(log.Fields{"prog":"openvpn","type":"Event"}).Infof("%s", event)
}

func (lc *loggingCallbacks) OnStats(stats openvpn3.Statistics) {
		log.WithFields(log.Fields{"prog":"openvpn","type":"Stat"}).Infof("%s", event)
}

var (
	vpn_file *string	
	callbacks *callbacks = &loggingCallbacs{}
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
	session := openvpn3.NewSession(config, creds, callbacks)

	session.Start()
	err = session.Wait()
	if err != nil {
		log.Fatal(err)
		return
	}
}
