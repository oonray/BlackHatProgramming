package main

import (
	"fmt"
	"flag"
	"net"
	"bufio"
	"io"
	log "github.com/sirupsen/logrus"
)

//const port int = 8081
//const con_port int = 3128

var (
	in net.Listener
	out net.Conn
	reader io.Reader
	writer io.Writer

	lport *string

	host *string
	port *string

	cons string
	lcons string

)

func argparse(){
	lport = flag.String("lp","","The port to listen on")
	host = flag.String("H","","The host to conenct to")
	port = flag.String("P","","The port to connect to")
	flag.Parse()
}

func main() {
	var err error

	argparse()

	cons = fmt.Sprintf("%s:%s",*host,*port)
	lcons = fmt.Sprintf(":%s",*lport)

	log.Infof("Listening on %s",lcons)
	in, err = net.Listen("tcp",lcons)
	if err != nil {
		log.Infof("Could not listen: %s",err)
		return
	}

	for {
		con, err := in.Accept()
		if err != nil {continue}

		log.Infof("Connecting to %s",cons)
		out, err = net.Dial("tcp",cons)
		if err != nil {
			log.Errorf("Could not connect: %s",err)
			return
		}

		reader := bufio.NewReader(con)
		writer := bufio.NewWriter(out)

		for {
			written, cerr := io.Copy(writer,reader)
			log.Infof("Wrote %d",written)
			if cerr != nil {
				log.Error(cerr)
				break
			}
		}
		con.Close()
	}
}
