//
// Created by Vlad Pyrch on 17/12/2023.
//

#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

stack_t* new_stack( const int capacity) {
    stack_t* stack = malloc(sizeof(stack_t));
    stack->capacity = capacity;
    stack->top = -1;
    stack->elements = calloc(capacity, sizeof(int));

    return stack;
}

void push(stack_t* stack, const int element) {
    stack->top++;
    stack->elements[stack->top] = element;
}

int pop(stack_t* stack) {
    stack->top--;

    return stack->elements[stack->top + 1];
}

int peek(const stack_t* stack) {
    return stack->elements[stack->top];
}

int is_empty(const stack_t* stack) {
    return stack->top == -1 ? 1 : 0;
}

int is_full(const stack_t* stack) {
    return stack->top == stack->capacity ? 1 : 0;
}

void clear(stack_t** stack) {
    free((*stack)->elements);
    free(*stack);
    *stack = NULL;
}
