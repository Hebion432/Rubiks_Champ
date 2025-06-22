cmake_minimum_required(VERSION 3.31)
project(RubiksChamp_V1)

set(CMAKE_CXX_STANDARD 20)

add_executable(RubiksChamp_V1 main.cpp
        cmake-build-debug/GenericRubiksCube.cpp
        cmake-build-debug/GenericRubiksCube.h
        Model/RubiksCube3d.cpp)
