//
//  linked_list_ptr.h
//  A-DS
//
//  Created by Isa Ertunga on 2023-04-22.
//

#ifndef linked_list_ptr_h
#define linked_list_ptr_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define L_ERROR     -9999

typedef struct PtrListNode {
    void* value;
    struct PtrListNode* next;
    struct PtrListNode* prev;
} PtrListNode;

typedef struct PtrList {
    int size;
    PtrListNode* head;
    PtrListNode* tail;
} PtrList;

/* INIT */
PtrList* ptr_init_list(void);

/* ADD */
void ptr_prepend(PtrList* list, void* value);
void ptr_append(PtrList* list, void* value);
void ptr_insert_at(PtrList* list, int index, void* value);

/* REMOVE */
PtrListNode* ptr_pop_front(PtrList* list);
PtrListNode* ptr_pop_back(PtrList* list);

/* GETTERS */
void* ptr_value_at(PtrList* list, int index);
int ptr_get_list_size(PtrList* list);

/* UTILS */
void ptr_print_list(PtrList* list);
void ptr_clean_list(PtrList* list);

#endif /* linked_list_ptr_h */
