cmake_minimum_required(VERSION "3.18")
project(ntmlbrute)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  include_directories(/opt/homebrew/include/)
  link_directories(/opt/homebrew/lib)
endif()

include_directories("src")
link_libraries(ca_string ca_vector ca_fileio ca_ringbuffer ca_munit)

#caaa

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
link_libraries(CURL::libcurl)

add_library(ntl_o OBJECT src/args.c src/request.c )
add_executable(ntmlbrute $<TARGET_OBJECTS:ntl_o> src/main.c)

add_executable(ntmlbrute_tests $<TARGET_OBJECTS:ntl_o> tests/ntmltest.c)
target_link_libraries(ntmlbrute_tests ca_munit)

add_test(NAME ntmlbrute_tests COMMAND ntmlbrute_tests)
