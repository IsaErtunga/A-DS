//
//  list-search.c
//  A-DS
//
//  Created by Isa Ertunga on 2023-02-26.
//

#include "list-search.h"


int binary_search(IntList* list, int value, int l, int r) {
    sort_list(list, &bubble_sort);
    int_print_list(list);
    int mid, index_value;
    while (l <= r) {
        mid = l + (r - l) / 2;
        index_value = int_value_at(list, mid);
        if (index_value == value) {
            return mid;
        } else if (index_value < value) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int search_list(IntList* list, int (*search_algorithm)(IntList*, int, int, int), int value) {
    // if needed
    int l = 0;
    int r = list->size - 1;

    return search_algorithm(list, value, l, r);
    
}
