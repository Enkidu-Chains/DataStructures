//
// Created by Vladyslav Pyrch on 17/12/2023.
//

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

typedef struct ListNode ListNode;

struct ListNode {
    int value;
    ListNode *next;
};

/**
 * \brief Creates a new node of the passed value and adds it as a tail to a linked list.
 * If <b>p_head</b> points to a pointer to NULL the function will initialize the first node of a linked list.
 * \param p_head A pointer to a pointer to the head of a linked list.
 * \param value A value to assign to a new node in a linked list.
 */
void list_node__add(ListNode **p_head, int value);

/**
 * \brief Removes the first occurrence of a node with the passed value from a linked list.
 * \param p_head A pointer to a pointer to the head of a linked list.
 * \param value The value of a node to remove from a linked list.
 * \return 0 if the node was successfully removed;<br/> -1 if there was nothing to remove.
 */
int list_node__remove(ListNode **p_head, int value);

/**
 * \brief Removes all the occurrences of nodes with the oassed value from the linked list.
 * \param p_head A pointer to a pointer to the head of a linked list.
 * \param value The value of nodes to remove from a linked list.
 * \return 0 if all the nodes was successfully removed;<br/> -1 if there was nothing to remove.
 */
int list_node__remove_all(ListNode **p_head, int value);

/**
 * \brief Frees allocated memory for all the nodes in a linked list and sets the potiner to the head to NULL pointer.
 * \param p_head A pointer to a pointer to the head of a linked list to clear.
 * \return 0 if a list was successfully cleard;<br/> -1 if a list was either already cleared or uninitialized.
 */
int list_node__clear(ListNode **p_head);

#endif //SINGLY_LINKED_LIST_H
