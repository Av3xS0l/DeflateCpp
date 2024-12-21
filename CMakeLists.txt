cmake_minimum_required(VERSION 3.10)
project(Deflate)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Deflate Main.h Main.cpp
        LZ77Item.cpp
        LZ77Item.h
        Symbol.cpp
        Symbol.h)