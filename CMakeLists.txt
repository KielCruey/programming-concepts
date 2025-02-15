cmake_minimum_required(VERSION 3.31)
project(Programming-Concepts VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")


add_library(linked-lists STATIC
            linked-lists/doubly-circular-linked-list/doubly-circular-linked-list.hpp
            #linked-lists/doubly-circular-linked-list/doubly-circular-linked-list.inl
            linked-lists/doubly-linked-list/doubly-linked-list.hpp
            #linked-lists/doubly-linked-list/doubly-linked-list.inl
            linked-lists/singly-circular-linked-list/singly-circular-linked-list.hpp
            #linked-lists/singly-circular-linked-list/singly-circular-linked-list.inl
            linked-lists/singly-linked-list/singly-linked-list.hpp
            #linked-lists/singly-linked-list/singly-linked-list.inl
            )

set_target_properties(linked-lists PROPERTIES LINKER_LANGUAGE CXX)


include_directories(.)

add_executable(programming-concepts programming-concepts.cpp)

target_link_libraries(programming-concepts PUBLIC linked-lists)