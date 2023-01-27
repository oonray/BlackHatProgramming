package main

import (
	"log"
	pb "rest/rpc/grpc/datafiles"

	context "golang.org/x/net/context"
	grpc "google.golang.org/grpc"
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

	c := pb.NewMoneyTransactionClient(con)
	r, err := c.MakeTransaction(context.Background(),
		&pb.TransactionRequest{
			From:   "1234",
			To:     "4321",
			Amount: float32(1234),
		})

	if err != nil {
		log.Fatalf("Could not transact %s", err)
	}

	log.Printf("%s", r)
}
