//
//  ptr_list_search.c
//  A-DS
//
//  Created by Isa Ertunga on 2023-04-23.
//

#include "ptr_list_search.h"

int ptr_search_list(PtrList* list, int (*searchAlgorithm)(PtrList*, void*), void* value) {
    return searchAlgorithm(list, value);
}
