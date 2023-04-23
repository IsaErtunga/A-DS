//
//  ptr_list_search.h
//  A-DS
//
//  Created by Isa Ertunga on 2023-04-23.
//

#ifndef ptr_list_search_h
#define ptr_list_search_h

#include <stdio.h>

#include "../data-structures/lists/linked_list_ptr.h"

int ptr_search_list(PtrList* list, int (*searchAlgorithm)(PtrList*, void*), void* value);

#endif /* ptr_list_search_h */
