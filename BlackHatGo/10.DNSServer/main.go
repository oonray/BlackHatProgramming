package main

import (
	"github.com/miekg/dns"
	"github.com/sirupsen/logrus"
	"net"
)

func main() {
	dns.HandleFunc(".", func(w dns.ResponseWriter, req *dns.Msg) {
		var resp dns.Msg

		resp.SetReply(req)
		for _, q := range req.Question {
			a := dns.A{
				Hdr: dns.RR_Header{
					Name:   q.name,
					Rrtype: dns.TypeA,
					Class:  dns.ClassINET,
					Ttl:    0,
				},
				A: net.ParseIP("127.0.0.1").To4(),
			}
			resp.Answer = appen(resp.Answer, &a)
		}
		w.WriteMsg(&resp)
	})
	logrus.Fatal(dns.ListenAndServer(":53", "udp", nil))
}
