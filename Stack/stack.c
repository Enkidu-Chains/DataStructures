//
// Created by Vlad Pyrch on 17/12/2023.
//

#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

stack_t* new_stack( const int capacity) {
    if (capacity < 1) {
        return NULL;
    }

    stack_t* stack = malloc(sizeof(stack_t));
    stack->capacity = capacity;
    stack->top = -1;
    stack->elements = calloc(capacity, sizeof(int));
    return stack;
}

int push(stack_t* stack, const int element) {
    if (stack == NULL || is_full(stack)) {
        return -1;
    }

    stack->top++;
    stack->elements[stack->top] = element;
    return 0;
}

int pop(stack_t* stack) {
    if (stack == NULL || is_empty(stack)) {
        return -1;
    }

    stack->top--;
    return 0;
}

int* peek(const stack_t* stack) {
    if (stack == NULL || is_empty(stack)) {
        return NULL;
    }

    return &stack->elements[stack->top];
}

int is_empty(const stack_t* stack) {
    return stack == NULL ? 0 : stack->top == -1 ? 1 : 0;
}

int is_full(const stack_t* stack) {
    return stack == NULL ? 0 : stack->top == stack->capacity ? 1 : 0;
}

int clear(stack_t** stack) {
    if (stack == NULL || *stack == NULL) {
        return -1;
    }

    free((*stack)->elements);
    free(*stack);
    *stack = NULL;
    return 0;
}
