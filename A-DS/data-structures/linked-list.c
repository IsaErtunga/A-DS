//
//  linked-list.c
//  A-DS
//
//  Created by Isa Ertunga on 2023-02-25.
//

#include "linked-list.h"

/**
 Create new list
 - inititalize size, head, tail
 */
List* init_list(void) {
    List* newList = (List*)malloc(sizeof(List));
    ListNode* head = NULL;
    ListNode* tail = NULL;
    
    newList->size = 0;
    newList->head = head;
    newList->tail = tail;
    
    return newList;
}

/* ---------- ADD ---------- */

/**
 Add to front
 - Rearrange head pointer to the new node
 - New node points to the previous head
 */
void prepend(List* list, void* value, uint8_t type) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->value = value;
    newNode->type = type;
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
void append(List* list, void* value, uint8_t type) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->value = value;
    newNode->type = type;
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
void insert_at_index(List* list, int index, void* new_value, int type) {
    if (index < 0 || index >= list->size) {
        printf("Selected index need to be inside range [0..%d]\n", list->size-1);
        return;
    }
    
    /* Traverse in the direction that is closer head or tail */
    ListNode* traversePtr;
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

    traversePtr->value = new_value;
    traversePtr->type = type;
    free(traversePtr);
}

/* ---------- Remove ---------- */

/**
 Removes from front of the lists
 Returns whole node
 */
ListNode* pop_front(List* list) {
    if (list->head == NULL) return (void*)L_ERROR; // TODO Fix this error
    
    /* Change head to point to second element */
    ListNode* poppedNode = list->head;
    
    if (poppedNode->next != NULL) {
        list->head = poppedNode->next;
        list->head->prev = NULL;
    } else {
        list->head = NULL;
        list->tail = NULL;
    }

    return poppedNode;
}

/**
 Removes front back of the list
 Returns whole node
 */
ListNode* pop_back(List* list) {
    if (list->tail == NULL) return (void*)L_ERROR; // TODO Fix this error
    
    /* Change head to point to second element */
    ListNode* poppedNode = list->tail;
    
    if (poppedNode->prev != NULL) {
        list->tail = poppedNode->prev;
        list->tail->next = NULL;
    } else {
        list->head = NULL;
        list->tail = NULL;
    }
    return poppedNode;
}


/* ---------- Higher order stuff (by reference) ---------- */
/**
 Creates list with given size.
 TODO: Create list from range like create_list_range(4, 8) -> [4,5,6,7]
 */
List* create_list(int size) {
    List* list = init_list();
    for (int i = size-1; i >= 0; i--) {
        prepend(list, &i, L_INT);
    }
    return list;
}

/**
 TODO Not working with void* generic type
 */
void list_map(List* list, int (*mapFunc)(int, int)) {
    // Empty list
    if (list->size == 0) return;
    
    ListNode* traversePtr = list->head;
    while (traversePtr != NULL) {
        int funcResult = (*mapFunc)(*(int*)traversePtr->value, 1);
        printf("%d\n", funcResult);
        free(traversePtr->value);
        traversePtr->value = (void*)&funcResult;
        traversePtr = traversePtr->next;
    }
}

/*
 TODO Not working with void* generic type
 */
void list_filter(List* list, int (*filter_func)(int, int), int filter_value) {
    if (list->head == 0) return;
    
    ListNode* current_node = list->head;
    ListNode* previous_node = list->head;

    while (current_node != NULL) {
        if ((*filter_func)(*(int*)current_node->value, filter_value) == 1) {
            previous_node = current_node;
            current_node = current_node->next;
            continue;
        };
        
        // remove
        previous_node->next = current_node->next;
        current_node = current_node->next;
        list->size = list->size - 1;
        free(current_node);
    }
}

//List* list_comprehension(List* list,
//                        int (*map_func)(int, int), int map_value,
//                        int (*filter_func)(int, int), int filter_value) {
//    list_map(list, map_func, map_value);
//    list_filter(list, filter_func, filter_value);
//    return list;
//}

/* ---------- Helpers ---------- */

ListNode* element_at(List* list, int index) {
    if (list->size == 0 || index > list->size-1) return list->head;
    
    // find element by index
    ListNode* traverse_ptr = list->head;
    for (int i = 0; i < index; i++) {
        traverse_ptr = traverse_ptr->next;
    }
    
    return traverse_ptr;
}

void print_list(List* list) {
    if (list->size == 0) {
        printf("Empty list\n");
        return;
    }
    
    ListNode* traverse_ptr = list->head;
    printf("[");
    while (traverse_ptr != NULL) {
        print_node_in_list(traverse_ptr);
        if (traverse_ptr->next != NULL) printf(", ");
        traverse_ptr = traverse_ptr->next;
    }
    printf("]\n");
}

void print_node_in_list(ListNode* node) {
    switch (node->type) {
        case L_INT:
            printf("%d", *(int*)node->value);
            break;
        case L_FLOAT:
            printf("%.3f", *(float*)node->value);
            break;
        case L_STRING:
            printf("%s", (char*)node->value);
            break;
        default:
            printf("Data type is not supported\n");
            break;
    }
}

void print_node(ListNode* node) {
    switch (node->type) {
        case L_INT:
            printf("%d\n", *(int*)node->value);
            break;
        case L_FLOAT:
            printf("%.3f\n", *(float*)node->value);
            break;
        case L_STRING:
            printf("%s\n", (char*)node->value);
            break;
        default:
            printf("Data type is not supported\n");
            break;
    }
}


int get_list_size(List* list) {
    return list->size;
}


/* ----------- Clean up -------------*/
void clean_list(List* list) {
    ListNode* traversePtr = list->head->next; // start at second node
    while (traversePtr != NULL) {
        free(traversePtr->prev);
        traversePtr = traversePtr->next;
    }
    free(traversePtr);
    free(list);
}
