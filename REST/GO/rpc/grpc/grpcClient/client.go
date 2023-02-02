package main

import (
	"context"
	"io"
	"log"
	pb "rest/rpc/grpc/datafiles"

	//context "golang.org/x/net/context"
	grpc "google.golang.org/grpc"
)

const (
	addr string = "localhost:9000"
)

func ReciveStream(client pb.MoneyTransactionClient, request *pb.TransactionRequest) {
	log.Println("Started listening to stream")
	stream, err := client.MakeTransaction(context.Background(), request)
	if err != nil {
		log.Fatalf("%v.MakeTransaction(..) = _, %v", client, err)
	}

	for {
		response, err := stream.Recv()
		if err == io.EOF {
			break
		}

		if err != nil {
			log.Fatalf("%v.MakeTransaction(..) = _, %v", client, err)
		}

		log.Printf("Status: %v, Operation: %v", response.Status, response.Step)
	}
}

func main() {
	con, err := grpc.Dial(addr, grpc.WithInsecure())
	if err != nil {
		log.Fatalf("Could not dial %s %s", addr, err)
		return
	}
	defer con.Close()

	c := pb.NewMoneyTransactionClient(con)
	ReciveStream(c, &pb.TransactionRequest{
		From:   "1234",
		To:     "4321",
		Amount: float32(1234),
	})

	/*r, err := c.MakeTransaction(context.Background(),
	&pb.TransactionRequest{
		From:   "1234",
		To:     "4321",
		Amount: float32(1234),
	})*/

	if err != nil {
		log.Fatalf("Could not transact %s", err)
	}
}
