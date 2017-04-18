cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(PengRobinson)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(PengRobinson ${SOURCES})