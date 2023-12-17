cmake_minimum_required(VERSION 3.27)
project(LinkedList C)

set(CMAKE_C_STANDARD 11)

add_executable(LinkedList main.c
        singly_linked_list.c
        singly_linked_list.h
        singly_linked_list_tests.c
        singly_linked_list_tests.h)
