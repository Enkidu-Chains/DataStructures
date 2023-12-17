//
// Created by Vlad Pyrch on 17/12/2023.
//

#ifndef SINGLY_LINKED_LIST_TESTS_H
#define SINGLY_LINKED_LIST_TESTS_H

int add_nullPointerAndAnyValue_initedLinkedList();

int add_validPointerAndAnyValue_linkedListWithNewTail();

int remove_nullPointerAndAnyValue_linkedListIsNullError();

int remove_middle_validPointerAndValue_linkedListWithoutNodeWithPassedValue();

int remove_tail_validPointerAndValue_linkedListWithoutNodeWithPassedValue();

int remove_head_validPointerAndValue_linkedListWithoutNodeWithPassedValue();

int remove_validPointerAndInvalidValue_ThereIsNoSuchNodeError();

int removeAll_nullPointerAndAnyValue_linkedListIsNullError();

int removeAll_validPointerAndValue_linkedListWithoutNodeWithPassedValue();

int removeAll_validPointerAndInvalidValue_ThereIsNoSuchNodeError();

int clear_nullPointer_linkedListIsAlreadyClearedOrUninitialized();

int clear_ValidPointer_PointerToNull();

void runTests();

#endif //SINGLY_LINKED_LIST_TESTS_H
