/** 
 * ================================================================
 * Name: Jeff Kwon
 * Section: T4A
 * Project: Header for Double-Linked List Library
 *
 * Instructions:  Complete the implementation file for this header file
 * =================================================================
 */
#ifndef LISTASDOUBLELINKEDLIST_H
#define LISTASDOUBLELINKEDLIST_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Define a node of the linked list
typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} Node;

// Define the type (meta-data) that manages the linked list of nodes
typedef struct {
    Node* head;
    Node* tail;
    int numberOfElements;
} DoubleLinkedList;

/** createLinkedList()
 * @brief  - initializes the linked list structure
 * @return - pointer to linked list
 * @pre    - nothing
 * @post   - new empty linked list returned
 */
DoubleLinkedList* createLinkedList();

/** deleteLinkedList(()
 * @brief  - deletes linked list, freeing all memory used
 * @param list - a ptr to the linked list structure
 * @pre    - unmodified linked list
 * @post   - the linked list is erased
 */
void deleteLinkedList(DoubleLinkedList* list);

/** appendElementLinkedList()
 * @brief - addes a new element to the end of the linked list
 * @param list - a ptr to the linked list structure
 * @param element - the value to append to the list
 * @pre   - linked list before element added
 * @post  - linked list one element longer
 */
void appendElementLinkedList(DoubleLinkedList* list, int element);

/** lengthOfLinkedList()
 * @brief  - returns the size of the linked list
 * @param list - a ptr to the linked structure
 * @return - number of items in the linked list
 * @pre    - linked list unmodified
 * @post   - linked list unmodified; size of linked list returned
 */
int lengthOfLinkedList(DoubleLinkedList* list);

/** printLinkedList()
 * @brief  - outputs the linked list to the console
 * @param list - the linked list structure
 * @pre    - linked list unmodified
 * @post   - linked list unmodified; linked list elements printed
 */
void printLinkedList(DoubleLinkedList* list);

/** getElementLinkedList()
 * @brief  - retrieves element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value requested
 * @return - value at 'position', -1 on failure
 * @pre    - unmodified linked list
 * @post   - unmodified linked list; value at 'position' returned
 */
int getElementLinkedList(DoubleLinkedList* list, int position);

/** deleteElementLinkedList()
 * @brief  - deletes element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value to delete
 * @pre    - unmodified linked list
 * @post   - modified linked list; value at 'position' removed
 */
void deleteElementLinkedList(DoubleLinkedList* list, int position);

/** insertElementLinkedList()
 * @brief  - adds element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value to add
 * @param  element - value to be added
 * @pre    - unmodified linked list
 * @post   - modified linked list; value add at 'position'
 */
void insertElementLinkedList(DoubleLinkedList* list, int position, int element);

/** changeElementLinkedList()
 * @brief  - changes element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value to add
 * @param  element - new value
 * @pre    - unmodified linked list
 * @post   - modified linked list; value changed at 'position'
 */
void changeElementLinkedList(DoubleLinkedList* list, int position, int newElement);

/** findElementLinkedList()
 * @brief  - finds the postion of a given element, if it exists
 * @param  list - a ptr to the linked list structure
 * @param  element - value to find
 * @pre    - unmodified linked list
 * @post   - unmodified linked list; position returned if found
 */
int findElementLinkedList(DoubleLinkedList* list, int element);

#endif  // LISTASDOUBLELINKEDLIST_H