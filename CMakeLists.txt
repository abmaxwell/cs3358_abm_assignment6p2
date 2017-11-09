cmake_minimum_required(VERSION 3.8)
project(cs3358_abm_assignment6p2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Assign06P2.cpp
        btNode.cpp
        btNode.h)

add_executable(cs3358_abm_assignment6p2 ${SOURCE_FILES})