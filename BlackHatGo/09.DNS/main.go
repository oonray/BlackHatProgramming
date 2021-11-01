package main

import (
	"flag"
    tea "github.com/charmbracelet/bubbletea"
)

var (
	Domain *string
	Wordlist *string
	Workers *int
	Server *string
)

func init(){
	Domain := flag.String("domain","","The domain to query")
	Wordlist := flag.String("wordlist","","The wordlist to use")
	WorkerCount := flag.Int("c",100,"The amount of workers")
	Server := flag.String("server","","The server to query")
	flag.Parse()
}

func main(){
	init()

}
