package main

import (
	"bytes"
	"context"
	"net"
	"os/exec"
	pb "reverse-grpc-server/reversepb"

	grpc "google.golang.org/grpc"
	"google.golang.org/grpc/reflection"
	"log"
	//"strings"
)

const (
	port string = ":9000"
)

type ReverseServer struct {
}

func (r *ReverseServer) Execute(c context.Context, in *pb.ReverseRequest) (*pb.ReverseResponse, error) {
	response := &pb.ReverseResponse{
		Std: &pb.Std{
			Out: "Hello",
		},
	}

	log.Printf("%s", in.Std.In)
	var std_out bytes.Buffer
	var std_err bytes.Buffer

	cmd := exec.Command("/bin/bash", "-c", in.Std.In)
	//cmd.Stdin = strings.NewReader(in.Std.In)
	cmd.Stdout = &std_out
	cmd.Stderr = &std_err

	err := cmd.Run()
	if err != nil {
		return response, err
	}

	response.Std.Out = std_out.String()
	response.Std.Err = std_err.String()

	return response, nil
}

func main() {
	lsn, err := net.Listen("tcp", port)
	if err != nil {
		log.Fatalf("Could not listen %s %s", port, err)
	}

	s := grpc.NewServer()

	srv := &ReverseServer{}
	pb.RegisterReverseTCPServer(s, srv)
	reflection.Register(s)

	if err := s.Serve(lsn); err != nil {
		log.Fatalf("Could not serve %s", err)
		return
	}
}
