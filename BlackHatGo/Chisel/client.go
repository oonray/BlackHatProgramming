package main

import (
	"flag"
	"fmt"
	"log"
	"net/http"
	"os"
	"strings"
	"time"

	client "github.com/oonray/BlackHatProgramming/BlackHatGo/Chisel/client"
	cos "github.com/oonray/BlackHatProgramming/BlackHatGo/Chisel/share/cos"
)

var (
	config client.Config = client.Config{Headers: http.Header{}}
	hostname *string
	verbose *bool

)

func main() {
	flag.StringVar(&config.Fingerprint, "fingerprint", "", "")
	flag.StringVar(&config.Auth, "auth", "", "")
	flag.DurationVar(&config.KeepAlive, "keepalive", 25*time.Second, "")
	flag.IntVar(&config.MaxRetryCount, "max-retry-count", -1, "")
	flag.DurationVar(&config.MaxRetryInterval, "max-retry-interval", 0, "")
	flag.StringVar(&config.Proxy, "proxy", "", "")
	flag.StringVar(&config.TLS.CA, "tls-ca", "", "")
	flag.BoolVar(&config.TLS.SkipVerify, "tls-skip-verify", false, "")
	flag.StringVar(&config.TLS.Cert, "tls-cert", "", "")
	flag.StringVar(&config.TLS.Key, "tls-key", "", "")
	flag.Var(&headerFlags{config.Headers}, "header", "")

	hostname = flag.String("hostname", "", "")
	verbose = flag.Bool("v", false, "")

	flag.Parse()
	args := flag.Args()
	if len(args) < 2 {
		log.Fatalf("A server and least one remote is required")
	}
	config.Server = args[0]
	config.Remotes = args[1:]
	//default auth
	if config.Auth == "" {
		config.Auth = os.Getenv("AUTH")
	}
	//move hostname onto headers
	if *hostname != "" {
		config.Headers.Set("Host", *hostname)
	}
	//ready
	c, err := client.NewClient(&config)
	if err != nil {
		log.Fatal(err)
	}
	c.Debug = *verbose
	go cos.GoStats()
	ctx := cos.InterruptContext()
	if err := c.Start(ctx); err != nil {
		log.Fatal(err)
	}
	if err := c.Wait(); err != nil {
		log.Fatal(err)
	}
}


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

type headerFlags struct {
	http.Header
}

func (flag *headerFlags) String() string {
	out := ""
	for k, v := range flag.Header {
		out += fmt.Sprintf("%s: %s\n", k, v)
	}
	return out
}

func (flag *headerFlags) Set(arg string) error {
	index := strings.Index(arg, ":")
	if index < 0 {
		return fmt.Errorf(`Invalid header (%s). Should be in the format "HeaderName: HeaderContent"`, arg)
	}
	if flag.Header == nil {
		flag.Header = http.Header{}
	}
	key := arg[0:index]
	value := arg[index+1:]
	flag.Header.Set(key, strings.TrimSpace(value))
	return nil
}
