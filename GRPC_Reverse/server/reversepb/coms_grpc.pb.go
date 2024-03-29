// Code generated by protoc-gen-go-grpc. DO NOT EDIT.
// versions:
// - protoc-gen-go-grpc v1.2.0
// - protoc             v3.12.4
// source: protobuff/coms.proto

package reversepb

import (
	context "context"
	grpc "google.golang.org/grpc"
	codes "google.golang.org/grpc/codes"
	status "google.golang.org/grpc/status"
)

// This is a compile-time assertion to ensure that this generated file
// is compatible with the grpc package it is being compiled against.
// Requires gRPC-Go v1.32.0 or later.
const _ = grpc.SupportPackageIsVersion7

// ReverseTCPClient is the client API for ReverseTCP service.
//
// For semantics around ctx use and closing/ending streaming RPCs, please refer to https://pkg.go.dev/google.golang.org/grpc/?tab=doc#ClientConn.NewStream.
type ReverseTCPClient interface {
	Execute(ctx context.Context, in *ReverseRequest, opts ...grpc.CallOption) (*ReverseResponse, error)
}

type reverseTCPClient struct {
	cc grpc.ClientConnInterface
}

func NewReverseTCPClient(cc grpc.ClientConnInterface) ReverseTCPClient {
	return &reverseTCPClient{cc}
}

func (c *reverseTCPClient) Execute(ctx context.Context, in *ReverseRequest, opts ...grpc.CallOption) (*ReverseResponse, error) {
	out := new(ReverseResponse)
	err := c.cc.Invoke(ctx, "/reverse.ReverseTCP/Execute", in, out, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

// ReverseTCPServer is the server API for ReverseTCP service.
// All implementations must embed UnimplementedReverseTCPServer
// for forward compatibility
type ReverseTCPServer interface {
	Execute(context.Context, *ReverseRequest) (*ReverseResponse, error)
}

// UnimplementedReverseTCPServer must be embedded to have forward compatible implementations.
type UnimplementedReverseTCPServer struct {
}

func (UnimplementedReverseTCPServer) Execute(context.Context, *ReverseRequest) (*ReverseResponse, error) {
	return nil, status.Errorf(codes.Unimplemented, "method Execute not implemented")
}
func (UnimplementedReverseTCPServer) mustEmbedUnimplementedReverseTCPServer() {}

// UnsafeReverseTCPServer may be embedded to opt out of forward compatibility for this service.
// Use of this interface is not recommended, as added methods to ReverseTCPServer will
// result in compilation errors.
type UnsafeReverseTCPServer interface {
	mustEmbedUnimplementedReverseTCPServer()
}

func RegisterReverseTCPServer(s grpc.ServiceRegistrar, srv ReverseTCPServer) {
	s.RegisterService(&ReverseTCP_ServiceDesc, srv)
}

func _ReverseTCP_Execute_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(ReverseRequest)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(ReverseTCPServer).Execute(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/reverse.ReverseTCP/Execute",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(ReverseTCPServer).Execute(ctx, req.(*ReverseRequest))
	}
	return interceptor(ctx, in, info, handler)
}

// ReverseTCP_ServiceDesc is the grpc.ServiceDesc for ReverseTCP service.
// It's only intended for direct use with grpc.RegisterService,
// and not to be introspected or modified (even as a copy)
var ReverseTCP_ServiceDesc = grpc.ServiceDesc{
	ServiceName: "reverse.ReverseTCP",
	HandlerType: (*ReverseTCPServer)(nil),
	Methods: []grpc.MethodDesc{
		{
			MethodName: "Execute",
			Handler:    _ReverseTCP_Execute_Handler,
		},
	},
	Streams:  []grpc.StreamDesc{},
	Metadata: "protobuff/coms.proto",
}
