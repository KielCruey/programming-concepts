# required for any cmake project
cmake_minimum_required(VERSION 3.31 FATAL_ERROR)

# names project and language
project(sharedLibs LANGUAGES CXX)

# create an executable using the shared lib
add_executable(main main.cpp)

# need to link the shared lib target called 'functions' to the executable
# or executable won't know what library's functions to use
target_link_libraries(main PRIVATE functions)




# https://blog.shaduri.dev/easily-create-shared-libraries-with-cmake-part-1