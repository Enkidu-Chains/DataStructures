cmake_minimum_required(VERSION 3.27)
project(Stack C)

set(CMAKE_C_STANDARD 11)

add_executable(Stack main.c
        stack.c
        stack.h
        stack_tests.c
        stack_tests.h
)
