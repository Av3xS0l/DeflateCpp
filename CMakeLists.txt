cmake_minimum_required(VERSION 3.10)
project(Deflate)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Deflate Main.h Main.cpp
        LZ77.cpp
        LZ77.h
        Symbol.cpp
        Symbol.h
        HuffmanNode.cpp
        HuffmanNode.h
        DataReader.cpp
        DataReader.h)