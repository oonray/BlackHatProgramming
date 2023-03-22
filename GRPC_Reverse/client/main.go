package main

import (
	"fmt"
	pb "reverse_grpc/reversepb"
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

	r, err := c.MakeTransaction(context.Background(),
		&pb.ReverseRequest{
			stdin: "ls", 
		},
	}
}
