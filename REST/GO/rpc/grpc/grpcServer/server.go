package main

import (
	context "golang.org/x/net/context"
	grpc "google.golang.org/grpc"
	//reflection "google.golang.org/grpc/reflection"
	"log"
	"net"
	pb "rest/rpc/grpc/datafiles"
)

const (
	port string = ":9000"
)

type server struct{}

func (s *server) MakeTransaction(ctx context.Context, in *pb.TransactionRequest) (*pb.TransactionResponse, error) {
	log.Printf("Got transaction request")
	log.Printf("Amount: %f, From A/c:%s, to A/c:%s", in.Amount, in.From, in.To)
	return &pb.TransactionResponse{Confirmation: true}, nil
}

func main() {
	lsn, err := net.Listen("tcp", port)
	if err != nil {
		log.Fatalf("Could not listen %s %s", port, err)
	}

	s := grpc.NewServer()

	srv := &server{}
	pb.RegisterMoneyTransactionServer(s, srv)

	if err := s.Serve(lsn); err != nil {
		log.Fatalf("Could not serve %s", err)
		return
	}
}
