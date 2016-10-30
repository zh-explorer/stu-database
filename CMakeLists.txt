cmake_minimum_required(VERSION 3.3)
project(student)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c main.h stdIO.c BRTree.c BRTree.h DatabaseControl.c SqlControl.c Control.c queryEx.c queryEx.h)
add_executable(student ${SOURCE_FILES})