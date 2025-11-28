cmake_minimum_required(VERSION 3.10)
project(ExpressionParser)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)

file(GLOB SOURCES "src/*.cpp")
add_executable(expression_parser ${SOURCES} main.cpp)
