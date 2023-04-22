//
//  linked-list-tests.c
//  A-DS
//
//  Created by Isa Ertunga on 2023-03-12.
//

#include "linked-list-tests.h"

void linked_list_test_add(void) {
    List* list = init_list();
    
    append(list, 1);
    append(list, 3);
    prepend(list, 2);
    append(list, 5);
    
    print_list(list);
    if (list->size == 4) {
        printf("Success!\n");
    }
    
    clean_list(list);

}

void linked_list_test_remove(void) {
    List* list = init_list();
        
    append(list, 1);
    append(list, 2);
    append(list, 3);
    append(list, 4);
    
    ListNode* val1 = pop_front(list);
    ListNode* val2 = pop_back(list);
    
    if (list->size == 2 && val1->value == 1 && val2->value == 4) {
        printf("Success!\n");
    }
    
    free(val1);
    free(val2);
    clean_list(list);
}

void linked_list_test_map(void) {
    List* list = init_list();
        
    append(list, 1);
    append(list, 2);
    append(list, 3);
    append(list, 4);
    
    list_map(list, &add, 1);
    print_list(list);
    
    clean_list(list);
}

void linked_list_test_filter(void) {
    List* list = init_list();
        
    append(list, 1);
    append(list, 2);
    append(list, 3);
    append(list, 4);
    
    list_map(list, &gt, 2);
    print_list(list);
    
    clean_list(list);
}
