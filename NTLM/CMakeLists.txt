cmake_minimum_required(VERSION "3.18")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
enable_testing()

project(ntmlbrute)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  include_directories(/opt/homebrew/include/)
  link_directories(/opt/homebrew/lib)
endif()

#caaa
link_libraries(ca_string ca_vector ca_fileio ca_ringbuffer)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
link_libraries(CURL::libcurl)

add_executable(ntmlbrute src/args.c src/request.c src/main.c)
