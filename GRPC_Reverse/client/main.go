package main

import (
	"context"
	grpc "google.golang.org/grpc"
	"log"
	pb "reverse-grpc-client/reversepb"
)

const (
	addr string = "localhost:9000"
)

func main() {
	con, err := grpc.Dial(addr, grpc.WithInsecure())
	if err != nil {
		log.Fatalf("Could not dial %s %s", addr, err)
		return
	}
	defer con.Close()

	c := pb.NewReverseTCPClient(con)
	r, err := c.Execute(context.Background(),
		&pb.ReverseRequest{
			Std: &pb.Std{
				In: "ls -lah",
			},
		},
	)

	if err != nil {
		log.Fatalf("error %s", err)
		return
	}

	log.Printf("%v", r)
}
