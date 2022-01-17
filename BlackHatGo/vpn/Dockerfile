FROM golang:latest
MAINTAINER oonray

RUN go get github.com/oonray/BlackHatProgramming/BlackHatGo/tcpforwarder
RUN go get github.com/oonray/BlackHatProgramming/BlackHatGo/oddproxy
RUN go get github.com/oonray/BlackHatProgramming/BlackHatGo/socks5

RUN apt-get update &&\
    apt-get install -y openvpn

WORKDIR /go/bin

CMD ["openvpn","/data/vpn/vpn.ovpn"]
