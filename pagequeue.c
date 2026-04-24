/** pagequeue.c
 * ===========================================================
 * Name: Jeff Kwon, 23 April 2026
 * Section: CS483 / M4
 * Project: PEX3 - Page Replacement Simulator
 * Purpose: Implementation of the PageQueue ADT — a doubly-linked
 *          list for LRU page replacement.
 *          Head = LRU (eviction end), Tail = MRU end.
 * =========================================================== */
#include <stdio.h>
#include <stdlib.h>

#include "pagequeue.h"

/**
 * @brief Create and initialize a page queue with a given capacity
 */
PageQueue *pqInit(unsigned int maxSize) {
    // TODO: malloc a PageQueue, set head and tail to NULL,
    //       size to 0, maxSize to maxSize, and return the pointer
    PageQueue *pq = (PageQueue*)malloc(sizeof(PageQueue));
    pq->head = NULL;
    pq->tail = NULL;
    pq->size = 0;
    pq->maxSize = maxSize;
    return pq;
}

/**
 * @brief Access a page in the queue (simulates a memory reference)
 */
long pqAccess(PageQueue *pq, unsigned long pageNum) {
    // TODO: Search the queue for pageNum (suggest searching tail->head
    //       so you naturally count depth from the MRU end).
    PqNode* current = pq->tail;
    int depth = 0;
    int hit = 0;

    while (current != NULL && hit == 0){
        if (current->pageNum == pageNum){
            hit = 1;
        } else {
            current = current->prev;
            depth += 1;
        }
    }

    // HIT path (page found at depth d):
    //   - Remove the node from its current position and re-insert
    //     it at the tail (most recently used).
    //   - Return d.
    if (hit == 1){
        // Already tail
        if (current == pq->tail){
            return depth; 
        }

        // At the head
        if (current == pq->head){
            // Set new node as head
            current->next->prev = NULL;
            pq->head = current->next;

        // In the middle
        } else {
            // Detach node
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }    
        
        current->prev = pq->tail;
        current->next = NULL;
        pq->tail->next = current;
        pq->tail = current;  

        return depth;

    } else {
    // MISS path (page not found):
    //   - Allocate a new node for pageNum and insert it at the tail.
    //   - If size now exceeds maxSize, evict the head node (free it).
    //   - Return -1.
        if (pq->size >= pq->maxSize){
            PqNode* tmp = pq->head;
            pq->head = pq->head->next;
            if (pq->head != NULL){
                pq->head->prev = NULL;
            } else {
                pq->tail = NULL;
            }
            free(tmp);
            pq->size -= 1;
        }

        PqNode* newNode = (PqNode*)malloc(sizeof(PqNode));
        newNode->pageNum = pageNum;  
        newNode->next = NULL;
        newNode->prev = pq->tail;
        if (pq->head == NULL){
            pq->head = newNode;
            pq->tail = newNode;
        } else {
            pq->tail->next = newNode;
        }  
        pq->tail = newNode;
        pq->size ++;

        return -1;
    }
}

/**
 * @brief Free all nodes in the queue and reset it to empty
 */
void pqFree(PageQueue *pq) {
    // TODO: Walk from head to tail, free each node, then free
    //       the PageQueue struct itself.
    PqNode* tmp = pq->head;
    while (tmp != NULL){
        pq->head = pq->head->next; // list->head now points to the node after the head node
        if (pq->head != NULL){
            pq->head->prev = NULL; // Node after head node now points back to nothing
        }
        free(tmp);
        pq->size -= 1;
        tmp = pq->head;
    }

    pq->head = NULL;
    pq->tail = NULL;
    free(pq);
}

/**
 * @brief Print queue contents to stderr for debugging
 */
void pqPrint(PageQueue *pq) {
    // TODO (optional): Print each page number from head to tail,
    //                  marking which is head and which is tail.
    //                  Useful for desk-checking small traces.
    if (pq->head == NULL){
        printf("Queue is empty\n");
        return;
    }
    PqNode* current = pq->head;
    printf("Node (Head): %ld\n", current->pageNum);

    while (current->next != NULL){
        current = current->next;
        printf("Node: %ld\n", current->pageNum);
    }
    printf("Node (tail): %ld\n", current->pageNum);
}
