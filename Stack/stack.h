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
 * \param capacity The capacity of a new stack.
 * \return A pointer to a new stack;<br>NULL pointer if capacity is less than 1.
 */
stack_t* new_stack(int capacity);


/**
 * \brief Pushes an element in the end of the stack.
 * \param stack A pointer to a stack to puch an element in.
 * \param element An elenment to puch in a stack.
 * \return 0 if an element is successfully pushed;<br>-1 if a pointer to a stack is NULL pointer or if a stack is full.
 */
int push(stack_t* stack, int element);

/**
 * \brief Removes the last element form the stack.
 * \param stack A pointer to a stack to pop the last element form.
 * \return 0 if the last element is successfully poped out of a stack;<br>-1 if A pointer to a stack is NULL pointer or if a stack is empty.
 */
int pop(stack_t* stack);

/**
 * \brief Returns a pointer to the last element in a stack.
 * \param stack A pointer to stack to peek the last element form.
 * \return A pointer to the last element in a stack;<br>NULL pointer if a pointer to a stak is NULL pointer or if a stakc is empty.
 */
int* peek(const stack_t* stack);

/**
 * \brief Checks wether a stack is empty or not.
 * \param stack A pointer to a stack to check wether it is empty.
 * \return 1 if a stack is empty;<br>0 if a stack has at least one elemnet or a pointer to it is NULL.
 */
int is_empty(const stack_t* stack);

/**
 * \brief Checks wether a stack is full or not.
 * \param stack A pointer to a stack to check wether it is full.
 * \return 1 if a stack is full;<br>0 if a stack has at least one elemnet or a pointer to it is NULL.
 */
int is_full(const stack_t* stack);

/**
 * \brief Clears the allocated to a stack memory and sets the pointer to a stack to NULL pointer.
 * \param stack A pointer to a pointer to a stack to clear.
 * \return 0 if stack is successfully cleard;<br>-1 if parameter stack is NULL pointer or points to NULL pointer.
 */
int clear(stack_t** stack);

#endif //STACK_H
