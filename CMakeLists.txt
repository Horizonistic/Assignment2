cmake_minimum_required(VERSION 3.3)
project(ComputerGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")



set(SOURCE_FILES main.cpp SuperOutput.cpp)
add_executable(ComputerGame ${SOURCE_FILES} SuperOutput.cpp SuperOutput.h)