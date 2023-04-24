cmake_minimum_required(VERSION "3.18")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
enable_testing()

project(ntmlbrute)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
link_libraries(CURL::libcurl)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  include_directories(/opt/homebrew/include/)
  link_directories(/opt/homebrew/lib)
endif()


add_executable(ntmlbrute src/main.c)
