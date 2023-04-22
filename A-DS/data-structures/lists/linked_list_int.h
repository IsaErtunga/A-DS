//
//  linked_list_int.h
//  A-DS
//
//  Created by Isa Ertunga on 2023-02-25.
//

#ifndef linked_list_int_h
#define linked_list_int_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define L_ERROR     -9999

typedef struct IntListNode {
    int value;
    struct IntListNode* next;
    struct IntListNode* prev;
} IntListNode;

typedef struct IntList {
    int size;
    IntListNode* head;
    IntListNode* tail;
} IntList;

/* INIT */
IntList* int_init_list(void);

/* ADD */
void int_prepend(IntList* list, int value);
void int_append(IntList* list, int value);
void int_insert_at(IntList* list, int index, int newValue);

/* REMOVE */
IntListNode* int_pop_front(IntList* list);
IntListNode* int_pop_back(IntList* list);

/* HIGHER ORDER STUFF */
IntList* int_create_list(int size);
IntList* int_list_map(IntList* list, int (*mapFunc)(int, int), int mapValue);
IntList* int_list_filter(IntList* list, int (*filterFunc)(int, int), int filterValue);
IntList* int_list_comprehension(IntList* list,
                         int (*map_func)(int, int), int map_value,
                         int (*filter_func)(int, int), int filter_value);


/* GETTERS */
int int_value_at(IntList* list, int index);
int int_get_list_size(IntList* list);

/* UTILS */
void int_print_list(IntList* list);
void int_clean_list(IntList* list);

#endif /* linked_list_int_h */
