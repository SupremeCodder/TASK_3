cmake_minimum_required(VERSION 3.23)
project(TASK3)

set(CMAKE_CXX_STANDARD 14)

include_directories(includes)

add_executable(TASK3 main.cpp ROV.cpp ROV.h Mission.cpp Mission.h Visitor.cpp Visitor.h)
