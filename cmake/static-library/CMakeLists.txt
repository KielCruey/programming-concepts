# required for any cmake project
cmake_minimum_required(VERSION 3.31 FATAL_ERROR)

# names project and language
project(staticLibs LANGUAGES CXX)

# generates static library from source
add_library(functions
	STATIC # keyword determines what type of lib
	functions.hpp
	functions.inl
	)

# create an executable using the static lib
add_executable(main main.cpp)

# need to link the static lib target called 'functions' to the executable
# or executable won't know what library's functions to use
target_link_libraries(main functions)

# makes sure the compilers knows that c++ is used for the static lib 
set_target_properties(functions PROPERTIES LINKER_LANGUAGE CXX)