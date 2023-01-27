### notes
go install google.golang.org/protobuf/cmd/protoc-gen-go@v1.28
go install google.golang.org/grpc/cmd/protoc-gen-go-grpc@v1.2


protoc -I protofiles protofiles/transfer.proto --go-grpc_out=. --go_out= .

https://www.youtube.com/watch?v=BdzYdN_Zd9Q

https://grpc.io/docs/languages/go/quickstart/
