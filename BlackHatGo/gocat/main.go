package main

import (
	"fmt"
	"os"
	"flag"
	log "github.com/sirupsen/logrus"
)

var (
	host *string
	port *int
	tcp  *bool
)

func init(){
	host = flag.String("-H","","What host to use")
	port = flag.Int("-p",0,"What port to user")
	tcp = flag.Bool("-t",false,"Wether to use TCP")
	flag.Parse()
}

func main() {
	
}
