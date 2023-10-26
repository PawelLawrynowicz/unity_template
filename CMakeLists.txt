project("Sample Project" C)
cmake_minimum_required(VERSION 3.0)

# Setting C standard to C17
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Set compilation flags
# Debug:
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -g -O0 -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer")
# Release:
# set(CMAKE C FLAGS "${CMAKE_C_FLAGS} -Os -Wall -Wextra -Wpedantic -s -flto")

# Update submodules automatically
include(cmake/UpdateSubmodules.cmake)

# Enable testing for this project
include(CTest)

# Make executable of the program
add_executable(executable src/main.c)

# BUILD_TESTING variable is created by include(CTest)
# It is set to ON by default
if(BUILD_TESTING)
  add_subdirectory(external)
  add_executable(test_executable test/main.c)   
  target_link_libraries(test_executable Unity)   
  target_include_directories(test_executable PRIVATE src)
  add_test(test test_executable)
endif()