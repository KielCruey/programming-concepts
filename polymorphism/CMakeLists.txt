cmake_minimum_required(VERSION 3.31 FATAL_ERROR)
project(Polymorphism VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin") # .exe and .dll
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib") # .so and .dylib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib") # .lib and .a

add_executable(polymorphism main.cpp)
add_library(polymorphism_lib polymorphism.cpp)
target_link_libraries(polymorphism polymorphism_lib)
file(COPY polymorphism.hpp DESTINATION "${CMAKE_BINARY_DIR}/include")

install(TARGETS polymorphism DESTINATION bin)
install(TARGETS polymorphism_lib DESTINATION lib)
#install(FILES polymorphism.hpp DESTINATION include)
