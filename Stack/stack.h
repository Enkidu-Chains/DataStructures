//
// Created by Vlad Pyrch on 17/12/2023.
//

#ifndef STACK_H
#define STACK_H

#include "../LinkedList/singly_linked_list.h"

typedef struct Stack stack_t;

struct Stack {
    int top;
    int capacity;
    int* elements;
};

/**
 * \brief Takes in capacity and creates a new stack with that capacity.
 * \param capacity The capacity of a new stack. Capacity should be bigger than or equal to 1.
 * \return A pointer to a new stack;
 */
stack_t* new_stack(int capacity);


/**
 * \brief Pushes an element in the end of the stack.
 * \param stack A pointer to a stack to puch an element in.
 * \param element An elenment to puch in a stack.
 */
void push(stack_t* stack, int element);

/**
 * \brief Removes the last element form the stack and returns it.
 * \param stack A pointer to a stack to pop the last element form.
 * \return a removed element.
 */
int pop(stack_t* stack);

/**
 * \brief Returns the last element in a stack.
 * \param stack A pointer to stack to peek the last element form.
 * \return the last element.
 */
int peek(const stack_t* stack);

/**
 * \brief Checks wether a stack is empty or not.
 * \param stack A pointer to a stack to check wether it is empty.
 * \return 1 if a stack is empty;<br>0 if a stack has at least one elemnet.
 */
int is_empty(const stack_t* stack);

/**
 * \brief Checks wether a stack is full or not.
 * \param stack A pointer to a stack to check wether it is full.
 * \return 1 if a stack is full;<br>0 if a stack has at least one elemnet.
 */
int is_full(const stack_t* stack);

/**
 * \brief Clears the allocated to a stack memory and sets the pointer to a stack to NULL pointer.
 * \param stack A pointer to a pointer to a stack to clear.
 */
void clear(stack_t** stack);

#endif //STACK_H
