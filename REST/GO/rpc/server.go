package main

/*
 * Needs to agre on args and values returned
 *
 */

import (
	log "github.com/sirupsen/logrus"
	"net"
	"net/http"
	"net/rpc"
	"time"
)

type Args struct{}
type TimeServer int64

func (t *TimeServer) GiveServerTime(args *Args, reply *int64) error {
	*reply = time.Now().Unix()
	return nil
}

func main() {
	srv := new(TimeServer)

	rpc.Register(srv)
	rpc.HandleHTTP()

	con, err := net.Listen("tcp", ":1234")
	if err != nil {
		log.Errorf("Could not listen %s", err)
		return
	}

	http.Serve(con, nil)
}
