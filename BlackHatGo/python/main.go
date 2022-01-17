package main

import (
	"flag"
	"errors"
	log "github.com/sirupsen/logrus"
    python "github.com/sbinet/go-python"
)

var (
	file *string
	str *string
)

func init(){
    python.Initialize()
}

func argparse() error {
	file := flag.String("f","","File to use")
	str := flag.String("c","","String to run")
	flag.Parse()
	if *str == "" && *file == "" {
		return errors.New("Need eighter string or file to execute")
	}
	if *str != "" && *file != "" {
		return errors.New("Need eighter string or file to execute, not both")
	}

	return nil
}

func main() {
	init()
    defer python.Finalize()

	err:=argparse()
	if err != nil {
		log.Fatal(err)
		flag.PrintDefaults()
		return
	}

	if *file != "" {  
		python.PyRun_SimpleFile(*file)
	}

	if *file != "" {  
		python.PyRun_SimpleString(*str)
		}
}
