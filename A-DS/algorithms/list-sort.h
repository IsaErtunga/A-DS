//
//  list-sort.h
//  A-DS
//
//  Created by Isa Ertunga on 2023-02-25.
//

#ifndef list_sort_h
#define list_sort_h

#include <stdio.h>
#include "../data-structures/lists/linked_list_int.h"

void bubble_sort(IntList* list);

void merge(IntList* list, int l, int m, int r);
void merge_sort_recur(IntList* list, int l, int r);
void merge_sort(IntList* list);


void sort_list(IntList* unsorted, void (*sortAlgorithm)(IntList*));

#endif /* list_sort_h */
