cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

project(Banking_System)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(app src/main.cpp src/Account.cpp src/TransactionStruct.cpp src/TransactionType.cpp)  # be sure there's exactly one main() function in the source files