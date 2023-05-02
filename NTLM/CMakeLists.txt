cmake_minimum_required(VERSION "3.18")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
enable_testing()

project(ntmlbrute)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  include_directories(/opt/homebrew/include/)
  link_directories(/opt/homebrew/lib)
endif()

include_directories("src")

#caaa
link_libraries(ca_string ca_vector ca_fileio ca_ringbuffer ca_munit)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
link_libraries(CURL::libcurl)

add_executable(ntmlbrute src/args.c src/request.c src/main.c)

add_executable(ntmlbrute_tests src/args.c src/request.c)
target_link_libraries(ntmlbrute_tests ca_munit)
add_test(ntmlbrute_tests)
