package main

import (
	"encoding/json"
	"fmt"
	grpc "google.golang.org/grpc"
	proto "google.golang.org/protobuf/proto"
	//protoc_gen "google.golang.org/protobuf/protoc-gen-go"
	pb "rest/rpc/grpc/addrbook"
)

func main() {
	p := &pb.Person{
		Id:    1234,
		Name:  "Roger F",
		Email: "rf@example.com",
		Phones: []*pb.Person_PhoneNumber{
			{Number: "555-4321", Type: pb.Person_HOME},
		},
	}

	p1 := &pb.Person{}
	body, _ := proto.Marshal(p)
	_ = proto.Unmarshal(body, p1)

	fmt.Printf("%v\n%v\n", p1, p)

	body, _ = json.Marshal(p)
	fmt.Printf("%s\n", body)
}
