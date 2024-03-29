//
//  linked_list_int.c
//  A-DS
//
//  Created by Isa Ertunga on 2023-02-25.
//

#include "linked_list_int.h"

/**
 Create new list
 - inititalize size, head, tail
 */
IntList* int_init_list(void) {
    IntList* newList = (IntList*)malloc(sizeof(IntList));
    IntListNode* head = NULL;
    IntListNode* tail = NULL;
    
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
void int_prepend(IntList* list, int value) {
    IntListNode* newNode = (IntListNode*)malloc(sizeof(IntListNode));
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
void int_append(IntList* list, int value) {
    IntListNode* newNode = (IntListNode*)malloc(sizeof(IntListNode));
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
void int_insert_at(IntList* list, int index, int newValue) {
    if (index < 0 || index >= list->size) {
        printf("Selected index need to be inside range [0..%d]\n", list->size-1);
        return;
    }
    
    /* Traverse in the direction that is closer head or tail */
    IntListNode* traversePtr;
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

    traversePtr->value = newValue;
    free(traversePtr);
}

/**
 Removes from front of the lists
 Returns whole node
 */
IntListNode* int_pop_front(IntList* list) {
    if (list->head == NULL) return (void*)L_ERROR; // TODO Fix this error
    
    /* Change head to point to second element */
    IntListNode* poppedNode = list->head;
    
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
IntListNode* int_pop_back(IntList* list) {
    if (list->tail == NULL) return (void*)L_ERROR; // TODO Fix this error
    
    /* Change head to point to second element */
    IntListNode* poppedNode = list->tail;
    
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

/**
 Creates list with given size.
 TODO: Create list from range like create_list_range(4, 8) -> [4,5,6,7]
 */
IntList* int_create_list(int size) {
    IntList* list = int_init_list();
    for (int i = size-1; i >= 0; i--) {
        int_prepend(list, i);
    }
    return list;
}

IntList* int_list_map(IntList* list, int (*mapFunc)(int, int), int mapValue) {
    IntList* newList = int_init_list();
    IntListNode* traversePtr = list->head;
    while (traversePtr != NULL) {
        int_prepend(newList, (*mapFunc)(traversePtr->value, mapValue));
        traversePtr = traversePtr->next;
    }
    return newList;
}

IntList* int_list_filter(IntList* list, int (*filterFunc)(int, int), int filterValue) {
    IntList* newList = int_init_list();
    IntListNode* traversePtr = list->head;
    while (traversePtr != NULL) {
        if ((*filterFunc)(traversePtr->value, filterValue)) {
            int_prepend(newList, traversePtr->value);
        }
        traversePtr = traversePtr->next;
    }
    return newList;
}

IntList* int_list_comprehension(IntList* list,
                        int (*map_func)(int, int), int mapValue,
                        int (*filter_func)(int, int), int filterValue) {
    return int_list_filter(int_list_map(list, map_func, mapValue), filter_func, filterValue);
}

/* ---------- Helpers ---------- */

int int_value_at(IntList* list, int index) {
    //if (list->size == 0 || index >= list->size) return list->head->value;
    
    // find element by index
    IntListNode* traversePtr = list->head;
    for (int i = 0; i < index; i++) {
        traversePtr = traversePtr->next;
    }
    
    return traversePtr->value;
}

// IntListNode* list_find(IntList* list, void* value, uint8_t type) {}

void int_print_list(IntList* list) {
    if (list->size == 0) {
        printf("Empty list\n");
        return;
    }
    
    IntListNode* traverse_ptr = list->head;
    printf("[");
    while (traverse_ptr != NULL) {
        printf("%d", traverse_ptr->value);
        if (traverse_ptr->next != NULL) printf(", ");
        traverse_ptr = traverse_ptr->next;
    }
    printf("]\n");
}

int int_get_size(IntList* list) {
    return list->size;
}


/* ----------- Clean up -------------*/
void int_clean_list(IntList* list) {
    IntListNode* traversePtr = list->head->next; // start at second node
    while (traversePtr != NULL) {
        free(traversePtr->prev);
        traversePtr = traversePtr->next;
    }
    free(traversePtr);
    free(list);
}
