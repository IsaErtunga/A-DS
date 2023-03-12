//
//  list-sort.h
//  A-DS
//
//  Created by Isa Ertunga on 2023-02-25.
//

#ifndef list_sort_h
#define list_sort_h

#include <stdio.h>
#include "../data-structures/linked-list.h"

void bubble_sort(List* list);

void merge(List* list, int l, int m, int r);
void merge_sort_recur(List* list, int l, int r);
void merge_sort(List* list);


void sort_list(List* unsorted, void (*sortAlgorithm)(List*));

#endif /* list_sort_h */
