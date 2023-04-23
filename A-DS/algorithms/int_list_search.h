//
//  int_list_search.h
//  A-DS
//
//  Created by Isa Ertunga on 2023-04-23.
//

#ifndef int_list_search_h
#define int_list_search_h

#include <stdio.h>

#include "../data-structures/lists/linked_list_int.h"
#include "./list-sort.h"

int binary_search_impl(IntList* list, int value, int l, int r);
int binary_search(IntList* list, int value);
int search_list(IntList* list, int (*searchAlgorithm)(IntList*, int), int value);

#endif /* int_list_search_h */
