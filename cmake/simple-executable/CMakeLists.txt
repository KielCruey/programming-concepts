# required for all cmake projects, if version is less than 3.31, then will throw an error
cmake_minimum_required(VERSION 3.31 FATAL_ERROR)

# project name and language
project(simple-executable LANGUAGES CXX)

# creates executable called "hello-cmake" by using main.cpp
add_executable(hello-cmake main.cpp)