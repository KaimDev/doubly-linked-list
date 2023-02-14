cmake_minimum_required(VERSION 3.24)

project(Doubly-linded-list C)

add_executable(program Main.c)

target_compile_features(program PUBLIC c_std_17)

set(CMAKE_BUILD_TYPE Debug)