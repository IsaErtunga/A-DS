//
//  linked_list_ptr.c
//  A-DS
//
//  Created by Isa Ertunga on 2023-04-22.
//

#include "linked_list_ptr.h"

/**
 Create new list
 - inititalize size, head, tail
 */
PtrList* ptr_init_list(void) {
    PtrList* newList = (PtrList*)malloc(sizeof(PtrList));
    PtrListNode* head = NULL;
    PtrListNode* tail = NULL;
    
    newList->size = 0;
    newList->head = head;
    newList->tail = tail;
    
    return newList;
}

/**
 Add to front
 - Rearrange head pointer to the new node
 - New node points to the previous head
 */
void ptr_prepend(PtrList* list, void* value) {
    PtrListNode* newNode = (PtrListNode*)malloc(sizeof(PtrListNode));
    newNode->value = value;
    newNode->prev = NULL;

    if (list->size <= 0) {
        list->tail = newNode;
        newNode->next = NULL;
    } else {
        list->head->prev = newNode;
        newNode->next = list->head;
    }
    
    list->head = newNode;
    list->size++;
}

/**
 Add to back
 - Rearrange last node pointer to the last node
 - Route new node pointer to NULL
 */
void ptr_append(PtrList* list, void* value) {
    PtrListNode* newNode = (PtrListNode*)malloc(sizeof(PtrListNode));
    newNode->value = value;
    newNode->next = NULL;
    
    if (list->size <= 0) { // first entry to the list
        list->head = newNode;
        newNode->prev = NULL;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
    }
    
    list->tail = newNode;
    list->size++;
}

/**
 Replace value at index
 */
void ptr_insert_at(PtrList* list, int index, void* value) {
    if (index < 0 || index >= list->size) {
        printf("Selected index need to be inside range [0..%d]\n", list->size-1);
        return;
    }
    
    /* Traverse in the direction that is closer head or tail */
    PtrListNode* traversePtr;
    if (index < (list->size/2)) {
        traversePtr = list->head;
        for (int i = 0; i < index; i++) {
            traversePtr = traversePtr->next;
        }
    } else {
        traversePtr = list->tail;
        for (int i = list->size-1; i > index; i--) {
            traversePtr = traversePtr->prev;
        }
    }

    traversePtr->value = value;
    free(traversePtr);
}

/**
 Removes from front of the lists
 Returns whole node
 */
PtrListNode* ptr_pop_front(PtrList* list) {
    if (list->head == NULL) return (void*)L_ERROR; // TODO Fix this error
    
    /* Change head to point to second element */
    PtrListNode* poppedNode = list->head;
    
    if (poppedNode->next != NULL) {
        list->head = poppedNode->next;
        list->head->prev = NULL;
    } else {
        list->head = NULL;
        list->tail = NULL;
    }
    
    list->size--;
    return poppedNode;
}

/**
 Removes front back of the list
 Returns whole node
 */
PtrListNode* ptr_pop_back(PtrList* list) {
    if (list->tail == NULL) return (void*)L_ERROR; // TODO Fix this error
    
    /* Change head to point to second element */
    PtrListNode* poppedNode = list->tail;
    
    if (poppedNode->prev != NULL) {
        list->tail = poppedNode->prev;
        list->tail->next = NULL;
    } else {
        list->head = NULL;
        list->tail = NULL;
    }
    
    list->size--;
    return poppedNode;
}

void* ptr_value_at(PtrList* list, int index) {
    //if (list->size == 0 || index >= list->size) return list->head->value;
    
    // find element by index
    PtrListNode* traversePtr = list->head;
    for (int i = 0; i < index; i++) {
        traversePtr = traversePtr->next;
    }
    
    return traversePtr->value;
}

int ptr_get_size(PtrList* list) {
    return list->size;
}


void ptr_clean_list(PtrList* list) {
    if (list->size == 0) {
        free(list->head);
        free(list->tail);
    } else if (list->size == 1) {
        free(list->head->next);
        free(list->head);
    } else if (list->size > 1) {
        PtrListNode* traversePtr = list->head->next;
        while (traversePtr != NULL) {
            free(traversePtr->prev);
            traversePtr = traversePtr->next;
        }
        free(traversePtr);
    }
    free(list);
}
