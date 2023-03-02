cmake_minimum_required(VERSION 3.17)
project(logger)

set(CMAKE_CXX_STANDARD 17)

include_directories("/")

add_executable(logger main.cpp Logger.hpp)