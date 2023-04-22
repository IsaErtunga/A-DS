//
//  list-sort.c
//  A-DS
//
//  Created by Isa Ertunga on 2023-02-25.
//

#include "list-sort.h"


void bubble_sort(IntList* list) {
//    int n = list->size;
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n-i-1; j++) {
//            int first_node_value = element_at(list, j)->value;
//            int second_node_value = element_at(list, j+1)->value;
//
//            if (first_node_value > second_node_value) {
//                replace_at(list, j, second_node_value);
//                replace_at(list, j+1, first_node_value);
//            }
//        }
//    }
}



void merge(IntList* list, int l, int m, int r) {
    
}

void merge_sort_recur(IntList* list, int l, int r) {
    if (l >= r) return;
    int m = (l + r)/2;
    
    merge_sort_recur(list, l, m);
    merge_sort_recur(list, m+1, r);
    
    merge(list, l, m, r);
}

void merge_sort(IntList* list) {
    int l = 1;
    int r = list->size;
    merge_sort_recur(list, l, r);
}


void sort_list(IntList* unsorted_list, void (*sortAlgorithm)(IntList*)) {
    sortAlgorithm(unsorted_list);
}


