package main

import (
	//context "golang.org/x/net/context"
	grpc "google.golang.org/grpc"
	"google.golang.org/grpc/reflection"
	"log"
	"net"
	pb "rest/rpc/grpc/datafiles"
	"time"
)

const (
	port  string = ":9000"
	steps int    = 3
)

type server struct{}

func (s *server) MakeTransaction(in *pb.TransactionRequest, stream pb.MoneyTransaction_MakeTransactionServer) error {
	log.Printf("Got transaction request")
	log.Printf("Amount: %f, From A/c:%s, to A/c:%s", in.Amount, in.From, in.To)
	for i := 0; i < steps; i++ {
		time.Sleep(time.Second * 2)
		if err := stream.Send(&pb.TransactionResponse{Status: "good", Step: int32(i)}); err != nil {
			log.Fatalf("%v.Send(%v) = %v", stream, "status", err)
		}
		log.Printf("Successfully transfered amount $%v from %v to %v", in.Amount, in.From, in.To)
	}
	return nil
}

func main() {
	lsn, err := net.Listen("tcp", port)
	if err != nil {
		log.Fatalf("Could not listen %s %s", port, err)
	}

	s := grpc.NewServer()

	srv := &server{}
	pb.RegisterMoneyTransactionServer(s, srv)
	reflection.Register(s)

	if err := s.Serve(lsn); err != nil {
		log.Fatalf("Could not serve %s", err)
		return
	}
}
