//
//  list-search.c
//  A-DS
//
//  Created by Isa Ertunga on 2023-02-26.
//

#include "list-search.h"


int binary_search(List* list, int value, int l, int r) {
    sort_list(list, &bubble_sort);
    print_list(list);
    int mid, index_value;
    while (l <= r) {
        mid = l + (r - l) / 2;
        index_value = element_at(list, mid)->value;
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

int search_list(List* list, int (*search_algorithm)(List*, int, int, int), int value) {
    // if needed
    int l = 0;
    int r = list->size - 1;

    return search_algorithm(list, value, l, r);
    
}
