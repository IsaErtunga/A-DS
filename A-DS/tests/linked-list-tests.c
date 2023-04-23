//
//  linked-list-tests.c
//  A-DS
//
//  Created by Isa Ertunga on 2023-03-12.
//

#include "linked-list-tests.h"

void linked_list_test_add(void) {
    IntList* list = int_init_list();
    
    int_append(list, 1);
    int_append(list, 3);
    int_prepend(list, 2);
    int_append(list, 5);
    
    int_print_list(list);
    if (list->size == 4) {
        printf("Success!\n");
    }
    
    int_clean_list(list);
}

void linked_list_test_remove(void) {
    IntList* list = int_init_list();
        
    int_append(list, 1);
    int_append(list, 2);
    int_append(list, 3);
    int_append(list, 4);
    
    IntListNode* val1 = int_pop_front(list);
    IntListNode* val2 = int_pop_back(list);
    
    if (list->size == 2 && val1->value == 1 && val2->value == 4) {
        printf("Success!\n");
    }
    
    free(val1);
    free(val2);
    int_clean_list(list);
}

void linked_list_test_map(void) {
    IntList* list = int_init_list();
        
    int_append(list, 1);
    int_append(list, 2);
    int_append(list, 3);
    int_append(list, 4);
    
    IntList* mappedList = int_list_map(list, &add, 1);
    int_print_list(mappedList);
    
    int_clean_list(list);
    int_clean_list(mappedList);
}

void linked_list_test_filter(void) {
    IntList* list = int_init_list();
        
    int_append(list, 1);
    int_append(list, 2);
    int_append(list, 3);
    int_append(list, 4);
    
    IntList* filteredList = int_list_filter(list, &gt, 2);
    int_print_list(filteredList);
    
    int_clean_list(filteredList);
    int_clean_list(list);
}

void linked_list_test_list_comprehension(void) {
    IntList* list = int_init_list();
        
    int_append(list, 1);
    int_append(list, 2);
    int_append(list, 3);
    int_append(list, 4);
    
    IntList* newList = int_list_comprehension(list, &add, 1, &gt, 2);
    int_print_list(newList);
    
    int_clean_list(newList);
    int_clean_list(list);
}

void linked_list_test_search(void) {
    IntList* list = int_init_list();
        
    int_append(list, 1);
    int_append(list, 2);
    int_append(list, 3);
    int_append(list, 4);
    int_append(list, 5);
    int_append(list, 6);
    int_append(list, 7);
    int_append(list, 8);

    int found = search_list(list, &binary_search, 4);
    printf("%d\n", found);
    
    int_clean_list(list);
}

void linked_list_test(void) {
    linked_list_test_search();
}
