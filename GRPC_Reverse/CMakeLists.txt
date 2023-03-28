cmake_minimum_required(VERSION 3.15)
project(GRPC_Reverse)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
  gRPC
  GIT_REPOSITORY https://github.com/grpc/grpc
  GIT_TAG        "v1.52.1"  # e.g v1.28.0
)
set(FETCHCONTENT_QUIET OFF)
FetchContent_MakeAvailable(gRPC)

include_directories(cpp_reversepb)

add_executable(client cpp_src/main.cpp cpp_reversepb/coms.pb.cc)
target_link_libraries(client grpc++)
