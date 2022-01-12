package main

import (
	"flag"
	"log"
	"os"
	"strings"
	"time"

	server "github.com/jpillora/chisel/server"
	cos "github.com/jpillora/chisel/share/cos"
)

var (
	config *server.Config = &server.Config{}
	host *string
	p  *string
	port *string
	verbose *bool
)

type multiFlag struct {
	values *[]string
}

func (flag multiFlag) String() string {
	return strings.Join(*flag.values, ", ")
}

func (flag multiFlag) Set(arg string) error {
	*flag.values = append(*flag.values, arg)
	return nil
}

func main(){
	flag.StringVar(&config.KeySeed, "key", "", "")
	flag.StringVar(&config.AuthFile, "authfile", "", "")
	flag.StringVar(&config.Auth, "auth", "", "")
	flag.DurationVar(&config.KeepAlive, "keepalive", 25*time.Second, "")
	flag.StringVar(&config.Proxy, "proxy", "", "")
	flag.StringVar(&config.Proxy, "backend", "", "")
	flag.BoolVar(&config.Socks5, "socks5", false, "")
	flag.BoolVar(&config.Reverse, "reverse", false, "")
	flag.StringVar(&config.TLS.Key, "tls-key", "", "")
	flag.StringVar(&config.TLS.Cert, "tls-cert", "", "")
	flag.Var(multiFlag{&config.TLS.Domains}, "tls-domain", "")
	flag.StringVar(&config.TLS.CA, "tls-ca", "", "")

	host = flag.String("host", "", "")
	p = flag.String("p", "", "")
	port = flag.String("port", "", "")
	verbose = flag.Bool("v", false, "")

	flag.Parse()

	if *host == "" {
		*host = os.Getenv("HOST")
	}
	if *host == "" {
		*host = "0.0.0.0"
	}
	if *port == "" {
		*port = *p
	}
	if *port == "" {
		*port = os.Getenv("PORT")
	}
	if *port == "" {
		*port = "8080"
	}
	if config.KeySeed == "" {
		config.KeySeed = os.Getenv("CHISEL_KEY")
	}
	s, err := server.NewServer(config)
	if err != nil {
		log.Fatal(err)
	}
	s.Debug = *verbose
	go cos.GoStats()
	ctx := cos.InterruptContext()
	if err := s.StartContext(ctx, *host, *port); err != nil {
		log.Fatal(err)
	}
	if err := s.Wait(); err != nil {
		log.Fatal(err)
	}
}
