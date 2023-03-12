//
//  linked-list-tests.c
//  A-DS
//
//  Created by Isa Ertunga on 2023-03-12.
//

#include "linked-list-tests.h"

void linked_list_test_add(void) {
    List* list = init_list();
    
    uint32_t i1 = 1;
    uint32_t i2 = 2;
    uint32_t i3 = 3;
    uint32_t i4 = 4;
    
    append(list, &i1, L_INT);
    append(list, &i2, L_INT);
    prepend(list, &i3, L_INT);
    append(list, &i4, L_INT);
    
//    insert_at_index(list, 0, &i4, L_INT);
    
    print_list(list);
    clean_list(list);

}


void linked_list_test_remove(void) {
    List* list = init_list();
    
    uint32_t i1 = 1;
    uint32_t i2 = 2;
    uint32_t i3 = 3;
    uint32_t i4 = 4;
    
    append(list, &i1, L_INT);
    append(list, &i2, L_INT);
    append(list, &i3, L_INT);
    append(list, &i4, L_INT);
    
    ListNode* val1 = pop_front(list);
    ListNode* val2 = pop_back(list);
    
    print_node(val1);
    print_node(val2);
    
    free(val1);
    free(val2);
    clean_list(list);
}



void linked_list_test_map(void) {
    List* list = init_list();
    
    uint32_t i1 = 1;
    uint32_t i2 = 2;
    uint32_t i3 = 3;
    uint32_t i4 = 4;
    
    append(list, &i1, L_INT);
    append(list, &i2, L_INT);
    append(list, &i3, L_INT);
    append(list, &i4, L_INT);
}
