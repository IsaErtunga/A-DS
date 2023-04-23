//
//  int_list_search.c
//  A-DS
//
//  Created by Isa Ertunga on 2023-02-26.
//

#include "int_list_search.h"

int binary_search_impl(IntList* list, int value, int l, int r) {
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

int binary_search(IntList* list, int value) {
    int l = 0;
    int r = list->size - 1;
    return binary_search_impl(list, value, l, r);
}

int int_search_list(IntList* list, int (*searchAlgorithm)(IntList*, int), int value) {
    return searchAlgorithm(list, value);
}
