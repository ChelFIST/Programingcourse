cmake_minimum_required(VERSION 3.23)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled1 libs/data_structures/vector/vector.c libs/data_structures/vector/vector.h main.c)
