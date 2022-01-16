FROM golang:latest
MAINTAINER oonray

RUN go get github.com/oonray/BlackHatProgramming/BlackHatGo/tcpforwarder
RUN go get github.com/oonray/BlackHatProgramming/BlackHatGo/oddproxy

RUN apt-get install openvpn

WORKDIR /go/bin

CMD ["openvpn","/data/vpn/vpn.ovpn"]
