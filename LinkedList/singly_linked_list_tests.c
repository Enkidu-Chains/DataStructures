//
// Created by Vladyslav Pyrch on 17/12/2023.
//
// todo Tests;

#include "singly_linked_list_tests.h"

#include <stdlib.h>
#include <stdio.h>
#include "singly_linked_list.h"

int add_nullPointerAndAnyValue_initedLinkedList() {
    printf("add_nullPointerAndAnyValue_initedLinkedList\n");
    ListNode *p_head = NULL;
    const int value = 1;

    list_node__add(&p_head, value);

    if (p_head == NULL) {
        printf("Linked list is supposed to be initialized.\n");
        return -1;
    }

    if (p_head->value != value) {
        printf("Linked list head node is assigned wrong value.\n");
        return -1;
    }

    if (p_head->next != NULL) {
        printf("Pointer to the next node is supposed to be NULL.\n");
        return -1;
    }

    list_node__clear(&p_head);
    return 0;
}

int add_validPointerAndAnyValue_linkedListWithNewTail() {
    printf("add_validPointerAndAnyValue_linkedListWithNewTail\n");
    ListNode *p_head = NULL;
    const int value1 = 1;
    const int value2 = 2;
    list_node__add(&p_head, value1); // init.

    list_node__add(&p_head, value2); // add new node

    if (p_head == NULL) {
        printf("Linked list is supposed to be initialized.\n");
        return -1;
    }

    if (p_head->value != value1) {
        printf("Pointer to the head of the linked list doesn't poiint to the head.\n");
        return -1;
    }

    ListNode *p_tail = p_head;
    for (;p_tail->next != NULL; p_tail = p_tail->next) {}

    if (p_tail->value != value2) {
        printf("The tail of the linked list doesn't have supposed value.\n");
        return -1;
    }

    if (p_tail->next != NULL) {
        printf("The tail's next should point to NULL.\n");
        return -1;
    }

    return 0;
}

int remove_nullPointerAndAnyValue_linkedListIsNullError() {
    printf("remove_nullPointerAndAnyValue_linkedListIsNullError\n");
    ListNode *p_head = NULL;
    const int value = 1;

    const int code = list_node__remove(&p_head, value);

    if (code != -1) {
        printf("The function hasn't detected that p_head is NULL pointer.\n");
        return -1;
    }

    return 0;
}

int remove_middle_validPointerAndValue_linkedListWithoutNodeWithPassedValue() {
    printf("remove_middle_validPointerAndValue_linkedListWithoutNodeWithPassedValue\n");
    ListNode *p_head = NULL;
    const int value1 = 1;
    const int value2 = 2;
    const int value3 = 3;
    list_node__add(&p_head, value1); //init
    list_node__add(&p_head, value2); //add
    list_node__add(&p_head, value3); //add

    //Remove form the middle
    list_node__remove(&p_head, value2);

    for (ListNode *node = p_head; node->next != NULL; node = node->next) {
        if (node->value == value2) {
            printf("An element form the middle of the list was not removed.\n");
            return -1;
        }
    }

    int length = 1;
    for (ListNode *node = p_head; node->next != NULL; node = node->next, length++) {}
    if (length != 2) {
        printf("The list was not connected correctly after element removing.\n");
        return -1;
    }

    list_node__clear(&p_head);
    return 0;
}

int remove_tail_validPointerAndValue_linkedListWithoutNodeWithPassedValue() {
    printf("remove_tail_validPointerAndValue_linkedListWithoutNodeWithPassedValue\n");
    ListNode *p_head = NULL;
    const int value1 = 1;
    const int value2 = 2;
    const int value3 = 3;
    list_node__add(&p_head, value1); //init
    list_node__add(&p_head, value2); //add
    list_node__add(&p_head, value3); //add

    //Remove the tail
    list_node__remove(&p_head, value3);

    for (ListNode *node = p_head; node->next != NULL; node = node->next) {
        if (node->value == value3) {
            printf("An element form the middle of the list was not removed.\n");
            return -1;
        }
    }

    int length = 1;
    for (ListNode *node = p_head; node->next != NULL; node = node->next, length++) {}
    if (length != 2) {
        printf("The list was not connected correctly after element removing.\n");
        return -1;
    }

    list_node__clear(&p_head);
    return 0;
}

int remove_head_validPointerAndValue_linkedListWithoutNodeWithPassedValue() {
    printf("remove_head_validPointerAndValue_linkedListWithoutNodeWithPassedValue\n");
    ListNode *p_head = NULL;
    const int value1 = 1;
    const int value2 = 2;
    const int value3 = 3;
    list_node__add(&p_head, value1); //init
    list_node__add(&p_head, value2); //add
    list_node__add(&p_head, value3); //add

    //Romve Head
    list_node__remove(&p_head, value1);

    for (ListNode *node = p_head; node->next != NULL; node = node->next) {
        if (node->value == value1) {
            printf("An element form the middle of the list was not removed.\n");
            return -1;
        }
    }

    int length = 1;
    for (ListNode *node = p_head; node->next != NULL; node = node->next, length++) {}
    if (length != 2) {
        printf("The list was not connected correctly after element removing.\n");
        return -1;
    }

    list_node__clear(&p_head);
    return 0;
}

int remove_validPointerAndInvalidValue_ThereIsNoSuchNodeError() {
    printf("remove_validPointerAndInvalidValue_ThereIsNoSuchNodeError\n");
    ListNode *p_head = NULL;
    const int value1 = 1;
    const int value2 = 2;
    const int value3 = 3;
    list_node__add(&p_head, value1); //init
    list_node__add(&p_head, value2); //add
    list_node__add(&p_head, value3); //add

    const int code = list_node__remove(&p_head, 4);

    if (code != -1) {
        printf("When there is nothing to remove the code is supposed to be -1");
        return -1;
    }

    list_node__clear(&p_head);
    return 0;
}

int removeAll_nullPointerAndAnyValue_linkedListIsNullError() {
    printf("removeAll_nullPointerAndAnyValue_linkedListIsNullError\n");
    ListNode *p_head = NULL;

    const int code = list_node__remove_all(&p_head, 1);

    if (code != -1) {
        printf("The function hasn't detected that p_head is NULL pointer.\n");
        return -1;
    }

    list_node__clear(&p_head);
    return 0;
}

int removeAll_validPointerAndValue_linkedListWithoutNodeWithPassedValue() {
    printf("removeAll_validPointerAndValue_linkedListWithoutNodeWithPassedValue\n");
    ListNode *p_head = NULL;
    const int values[] = {1, 3, 3, 3, 5, 3, 5, 2, 3};

    for (int i = 0; i <= sizeof(values)/sizeof(int); i++) {
        list_node__add(&p_head, values[i]);
    }

    const int code = list_node__remove_all(&p_head, 3);

    if (code != 0) {
        printf("It thinks that a linked list is empty to begin with.\n");
        return -1;
    }

    list_node__clear(&p_head);
    return 0;
}

int removeAll_validPointerAndInvalidValue_ThereIsNoSuchNodeError() {
    printf("removeAll_validPointerAndInvalidValue_ThereIsNoSuchNodeError\n");
    ListNode *p_head = NULL;
    const int values[] = {1, 3, 3, 3, 5, 3, 5, 2, 3};

    for (int i = 0; i <= sizeof(values)/sizeof(int); i++) {
        list_node__add(&p_head, values[i]);
    }

    const int code = list_node__remove_all(&p_head, 10);

    if (code != -1) {
        printf("It hasn't removed anything and yet said it did.\n");
        return -1;
    }

    list_node__clear(&p_head);
    return 0;
}

int clear_nullPointer_linkedListIsAlreadyClearedOrUninitialized() {
    printf("clear_nullPointer_linkedListIsAlreadyClearedOrUninitialized\n");
    ListNode *p_head = NULL;

    const int code = list_node__clear(&p_head);

    if (code != -1) {
        printf("It shomehow cleared NULL pointer. Impossible.");
        return -1;
    }

    return 0;
}

int clear_ValidPointer_PointerToNull() {
    printf("clear_ValidPointer_PointerToNull\n");
    ListNode *p_head = NULL;
    const int values[] = {1, 3, 3, 3, 5, 3, 5, 2, 3};

    for (int i = 0; i <= sizeof(values)/sizeof(int); i++) {
        list_node__add(&p_head, values[i]);
    }

    const int code = list_node__clear(&p_head);

    if (code != 0) {
        printf("An error ocured during clearing");
        return -1;
    }

    if (p_head != NULL) {
        printf("The function havn't set a pointer to null pointer. posibility of trying to use unallocated memory.");
        return -1;
    }

    return 0;
}

void runTests() {
    add_nullPointerAndAnyValue_initedLinkedList() == -1 ?
        printf("-Error\n\n") : printf("-Passed\n\n");
    add_validPointerAndAnyValue_linkedListWithNewTail() == -1 ?
        printf("-Error\n\n") : printf("-Passed\n\n");

    remove_nullPointerAndAnyValue_linkedListIsNullError() == -1 ?
        printf("-Error\n\n") : printf("-Passed\n\n");
    remove_middle_validPointerAndValue_linkedListWithoutNodeWithPassedValue() == -1 ?
        printf("-Error\n\n") : printf("-Passed\n\n");
    remove_tail_validPointerAndValue_linkedListWithoutNodeWithPassedValue() == -1 ?
        printf("-Error\n\n") : printf("-Passed\n\n");
    remove_head_validPointerAndValue_linkedListWithoutNodeWithPassedValue() == -1 ?
        printf("-Error\n\n") : printf("-Passed\n\n");
    remove_validPointerAndInvalidValue_ThereIsNoSuchNodeError() == -1 ?
        printf("-Error\n\n") : printf("-Passed\n\n");

    removeAll_nullPointerAndAnyValue_linkedListIsNullError() == -1 ?
        printf("-Error\n\n") : printf("-Passed\n\n");
    removeAll_validPointerAndValue_linkedListWithoutNodeWithPassedValue() == -1 ?
        printf("-Error\n\n") : printf("-Passed\n\n");
    removeAll_validPointerAndInvalidValue_ThereIsNoSuchNodeError() == -1 ?
        printf("-Error\n\n") : printf("-Passed\n\n");

    clear_nullPointer_linkedListIsAlreadyClearedOrUninitialized() == -1 ?
        printf("-Error\n\n") : printf("-Passed\n\n");
    clear_ValidPointer_PointerToNull() == -1 ?
        printf("-Error\n\n") : printf("-Passed\n\n");
}