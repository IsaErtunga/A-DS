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

typedef struct ListNode {
    int value;
    struct ListNode* next;
    struct ListNode* prev;
} ListNode;

typedef struct List {
    int size;
    ListNode* head;
    ListNode* tail;
} List;

/* INIT */
List* init_list(void);

/* ADD */
void prepend(List* list, int value);
void append(List* list, int value);
void insert_at(List* list, int index, int newValue);

/* REMOVE */
ListNode* pop_front(List* list);
ListNode* pop_back(List* list);

/* HIGHER ORDER STUFF */
List* create_list(int size);
bool list_map(List* list, int (*mapFunc)(int, int), int mapValue);
void list_filter(List* list, int (*filter_func)(int, int), int filter_value);
List* list_comprehension(List* list,
                         int (*map_func)(int, int), int map_value,
                         int (*filter_func)(int, int), int filter_value);


/* HELPERS */
ListNode* value_at(List* list, int index);
int get_list_size(List* list);
void print_list(List* list);
void clean_list(List* list);

#endif /* linked_list_int_h */
