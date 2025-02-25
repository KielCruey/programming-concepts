# List all library sources
set(FUNCTIONS_SOURCES functions.cpp functions.hpp)

# Add a shared library target
add_library(functions SHARED ${FUNCTIONS_SOURCES})

# Export the library's public header path to dependent targets
target_include_directories(functions
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)