package main

import (
	log "github.com/sirupsen/logrus"
	"net/rpc"
	"time"
)

const (
	addr string = "localhost:1234"
	call string = "TimeServer.GiveServerTime"
)

var (
	reply int64
	args  Args = Args{}
)

type Args struct{}

func main() {
	client, err := rpc.DialHTTP("tcp", addr)
	if err != nil {
		log.Errorf("Could not connect to %s | %s", addr, err)
		return
	}

	err = client.Call(call, args, &reply)
	if err != nil {
		log.Errorf("Could not call %s | %s", call, err)
		return
	}

	log.Infof("Got %d, %s", reply, time.Unix(reply, 0))
}
