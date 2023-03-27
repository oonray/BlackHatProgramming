
cmake_minimum_required(VERSION "3.18")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
enable_testing()
include(CPack)

project(snake)

find_package(Curses REQUIRED)

include_directories(${CURSES_INCLUDE_DIR})
link_libraries(${CURSES_LIBRARIES})

include_directories(src)
include_directories(inc)

FILE(GLOB src "src/*.cpp")
list(FILTER src EXCLUDE REGEX "main")

#executable
add_executable(snake src/main.cpp)
