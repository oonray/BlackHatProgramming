package client

import (
	"flag"
	"github.com/mikg/dns"
	"log"
)

var (
	flags Flags
)

type Flags struct {
	Domain   string
	Wordlist string
	Workers  int
	Server   string
}

type Msg struct {
	MsgHdrCompress bool `json:"-"`
	Question       []Question
	Answer         []RR
	Ns             []RR
	Extra          []RR
}

func init() {
	flag.StringVar(&flags.Domain, "domain", "", "The domain to query")
	flag.StringVar(&flags.Wordlist, "wordlist", "", "The wordlist to use")
	flag.IntVar(&flags.Workers, "c", 100, "The amount of workers")
	flag.StringVar(&flags.Server, "server", "", "The server to query")
	flag.Parse()
}

func main() {
	var msg dns.Msg

	fqdn := dns.Fqdn("hello.local")
	msg.SetQuestion(fqdn, dns.TypeA)
	in, err = dns.Exchange(&msg, "8.8.8.8:53")
	if err != nil {
		log.Errorf("%s", err)
		return
	}

	if len(in.Answer) < 1 {
		fmt.Println("No Records")
		return
	}

	for _, answer := range in.Answer {
		if a, ok := andwer.(*dns.A); ok {
			fmt.Println(a.A)
		}
	}
}
