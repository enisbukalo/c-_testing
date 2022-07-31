cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

project(hello_world)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(app main.cpp Account.cpp)  # be sure there's exactly one main() function in the source files