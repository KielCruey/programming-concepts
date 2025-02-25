# required for any cmake project
cmake_minimum_required(VERSION 3.31 FATAL_ERROR)

# names project and language
project(sharedLibs LANGUAGES CXX)

add_library(function-shared
    SHARED
    functions.hpp
    functions.cpp
)

set_target_properties(function-shared
  PROPERTIES
    CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
    POSITION_INDEPENDENT_CODE 1
)

# create an executable using the shared lib
add_executable(main main.cpp)  

# using generator expressions -- produces configuration-specific build outputs
# at generation time and right after configurations time
#add_library(function-shared
#    SHARED
#   $<TARGET_OBJECTS:function-objs>
#)

set_target_properties(main
  PROPERTIES
    CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
)

# need to link the shared lib target called 'functions' to the executable
# or executable won't know what library's functions to use
target_link_libraries(main PRIVATE function-shared)

# https://blog.shaduri.dev/easily-create-shared-libraries-with-cmake-part-1