cmake_minimum_required(VERSION 3.16)
project(rest LANGUAGES C VERSION 0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
enable_testing()

add_executable(webserver inc/mongoose/mongoose.c src/webserver.c  src/main.c)
target_include_directories(webserver PRIVATE inc/mongoose)
