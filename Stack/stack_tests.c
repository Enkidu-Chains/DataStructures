//
// Created by Vlad Pyrch on 17/12/2023.
//

#include "stack_tests.h"

#include <stdio.h>

#include "stack.h"
//Todo normal tests.
void test__new_stack() {
    printf("test__new_stack\n");
    // capacity less than 1;
    stack_t* stack = new_stack(-1);

    if (stack != NULL) {
        stack
    }

}

void test__push() {
}

void test__pop() {
}

void test__peek() {
}

void test__is_empty() {
}

void test__is_full() {
}

void test__clear() {
}
