/** 
 * ================================================================
 * Name: Jeff Kwon
 * Section: T4A
 * Project: Implementation of Double-Linked List Library
 * =================================================================
 */
#include "listAsDoubleLinkedList.h"

DoubleLinkedList* createLinkedList(){
    DoubleLinkedList* list = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));;
    list->head = NULL;
    list->tail = NULL;
    list->numberOfElements = 0;
    return list;
}

void deleteLinkedList(DoubleLinkedList* list){
    Node* tmp = list->head;
    while (tmp != NULL) {
        list->head = list->head->next; // list->head now points to the node after the head node
        if (list->head != NULL){
            list->head->prev = NULL; // Node after head node now points back to nothing
        }
        free(tmp); // Free the head node
        list->numberOfElements -= 1; // Size of list decreases
        tmp = list->head; // Temp pointer now points to new head node
    } 

    list->head = NULL;
    list->tail = NULL;
    list->numberOfElements = 0;
    free(list);
}

void appendElementLinkedList(DoubleLinkedList* list, int element){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = element;    
    newNode->prev = list->tail;
    if (list->head == NULL){
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
    }  
    list->tail = newNode;
    list->numberOfElements++;
}

int lengthOfLinkedList(DoubleLinkedList* list){
    int length = 0;
    Node* current = list->head;    

    while (current != NULL) {        
        length += 1;     
        current = current->next;    
    }
    return length;
}

void printLinkedList(DoubleLinkedList* list){
    Node* current = list->head;    
    while (current != NULL) {        
        printf("%d\n", current->data);        
        current = current->next;    
    }
}

int getElementLinkedList(DoubleLinkedList* list, int position){
    // Checks if the List is empty
    if (list == NULL || list->head == NULL){
        printf("The list is empty\n");
        return - 1;
    }

    Node* current = list->head;

    for (int i = 0; i < position; i++){
        if (current == NULL){
            printf("Position Out of Bounds\n");
            return -1;

        }
        current = current->next;
    }
    if (current != NULL){
        return current->data;
    } else {
        printf("Position Out of Bounds\n");
        return -1;
    }
}

void deleteElementLinkedList(DoubleLinkedList* list, int position){
    // Checks if the List is empty
    if (list == NULL || list->head == NULL){
        printf("The list is empty\n");
        exit(0);
    }

    Node* current = list->head;
    if (position == 0){
        list->head = current->next;
        if (list->head == NULL){
            list->tail = NULL;
        }
    } else {
        Node* previous = NULL;
        for (int i = 0; i < position; i++){
            if (current != NULL){
                previous = current;
                current = current->next;
            } else {
                printf("Position Out of Bounds\n");
                return;
            }
        }
        current->next->prev = previous;
        previous->next = current->next;
        if (current->next == NULL){
            list->tail = previous;
        }
    }
    list->numberOfElements--;  
}

void insertElementLinkedList(DoubleLinkedList* list, int position, int element){
    // ensure postition is in range
    if (position < 0 || position > list->numberOfElements){
        printf("Error\n");
        exit(0);
    }
   
    // create a new node on the heap as values on the stack
    // are free'd when the function ends
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Memory Allocation Failed\n");
        exit(0);
    }
    newNode->data = element;
    newNode->next = NULL;
    newNode->prev = NULL;
   
   // traverse linked list until curPos == position 
    int curPos = 0;
    Node* tempPtr = list->head;
    if (list->numberOfElements == 0){
        list->head = newNode;
        list->tail = newNode;
    } else if (position == 0){
        newNode->next = tempPtr;
        tempPtr->prev = newNode;
        list->head = newNode;
    } else if (position == list->numberOfElements){
        newNode->prev = tempPtr;
        tempPtr->next = newNode;
        list->tail = newNode;
    } else {
        while (tempPtr != NULL && curPos < position) {
            curPos++;
            tempPtr = tempPtr->next;
        }
        newNode->prev = tempPtr->prev;
        newNode->next = tempPtr;
        tempPtr->prev->next = newNode;
        tempPtr->prev = newNode;
    }

   
   // increase number of elements
   list->numberOfElements++;
}

void changeElementLinkedList(DoubleLinkedList* list, int position, int newElement){
    Node* current = list->head;

    for (int i = 0; i < position; i++){
        current = current->next;
    }
    current->data = newElement;
}

int findElementLinkedList(DoubleLinkedList* list, int element){
    if (list == NULL || list->head == NULL){
        printf("The list is empty\n");
        exit(0);
    }
    Node* current = list->head;
    int position = 0;

    while (current != NULL && current->data != element){
        current = current->next;
        position += 1;
    }
    return position;
}
