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
#include <stdint.h>
#include <stdbool.h>

#include "../hash-maps/hash_map_int.h"

#define L_INT       0
#define L_FLOAT     1
#define L_STRING    2
#define L_KEYVALUE  3
#define L_ERROR     -9999


typedef struct ListNode {
    void* value;
    uint8_t type;           // 0: int, 1: float, 2: string
    struct ListNode* next;
    struct ListNode* prev;
} ListNode;

typedef struct List {
    int size;
    ListNode* head;
    ListNode* tail;
} List;

List* init_list(void);

void prepend(List* list, void* value, uint8_t type);
void append(List* list, void* value, uint8_t type);

void insert_at_index(List* list, int index, void* new_value, int type);
ListNode* pop_front(List* list);
ListNode* pop_back(List* list);

List* create_list(int size);
void list_map(List* list, int (*mapFunc)(int, int));
void list_filter(List* list, int (*filter_func)(int, int), int filter_value);
List* list_comprehension(List* list,
                         int (*map_func)(int, int), int map_value,
                         int (*filter_func)(int, int), int filter_value);

ListNode* element_at(List* list, int index);
void print_list(List* list);
void print_node_in_list(ListNode* node);
void print_node(ListNode* node);
int get_list_size(List* list);

void clean_list(List* list);

#endif /* linked_list_int_h */
