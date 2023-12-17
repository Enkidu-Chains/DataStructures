//
// Created by Vladyslav Pyrch on 17/12/2023.
//

#include "singly_linked_list.h"

#include <stdlib.h>

void list_node__add(ListNode **p_head, const int value) {
    ListNode *p_newNode = malloc(sizeof(ListNode));
    p_newNode->value = value;
    p_newNode->next = NULL;

    // If a pointer to a pointer to a head points to NULL, a list is uninitialized;
    if (*p_head == NULL) {
        *p_head = p_newNode;
        return;
    }

    ListNode *p_localHead = *p_head;

    // Seeking the tail of the list
    for (; p_localHead->next; p_localHead = p_localHead->next) {}

    p_localHead->next = p_newNode;
}

int list_node__remove(ListNode **p_head, const int value) {
    ListNode *p_localHead = *p_head;
    ListNode *p_previous = NULL;

    for (; p_localHead->next; p_localHead = p_localHead->next, p_previous = p_localHead) {
        // Skips all the notdes which value is not equal to the passed one.
        if (p_localHead->value != value) {
            continue;
        }
        // If a node to remove is the head, it changes the head of a list to the next node.
        if (p_previous != NULL) {
            p_previous->next = p_localHead->next;
        } else {
            *p_head = p_localHead->next;
        }
        free(p_localHead);
        return 0;
    }

    // Nothing was removed from a list.
    return -1;
}

int list_node__remove_all(ListNode **p_head, const int value) {
    int removed_code = list_node__remove(p_head, value);

    // If removed code is equal to -1 the first time we try to remove a node with the passed value,
    // nothing was removed from the list.
    if (removed_code == -1) {
        return -1;
    }

    // Remove until there is nothing to remove.
    while (removed_code != -1) {
        removed_code = list_node__remove(p_head, value);
    }

    return 0;
}

// Recursively clears the memory.
void _list_node__clear(ListNode *p_head) {
    if (p_head == NULL) {
        return;
    }
    _list_node__clear(p_head->next);
    free(p_head);
}

int list_node__clear(ListNode **p_head) {
    // Linked list is already cleard or uninitialized.
    if (*p_head == NULL) {
        return -1;
    }

    _list_node__clear(*p_head);
    *p_head = NULL;
    return 0;
}
