//
//  list-search.h
//  A-DS
//
//  Created by Isa Ertunga on 2023-02-26.
//

#ifndef list_search_h
#define list_search_h

#include <stdio.h>

#include "../data-structures/linked-list.h"
#include "./list-sort.h"


int binary_search(List* list, int value, int l, int r);

int search_list(List* list, int (*search_algorithm)(List*, int, int, int), int value);

#endif /* list_search_h */