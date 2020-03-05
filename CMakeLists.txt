cmake_minimum_required(VERSION 3.10)
# set the project name
project(alg)

set(CMAKE_BUILD_TYPE Debug)
set(SOURCES main.cpp PrintCommand.cpp Token.cpp Parser.cpp)
add_executable(alg ${SOURCES})
