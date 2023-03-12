//
//  hash-map-tests.c
//  A-DS
//
//  Created by Isa Ertunga on 2023-03-12.
//

#include "hash-map-tests.h"


void hash_map_test(void) {
    HashMap* hashMap = init_hash_map();
    
    uint32_t i1 = 1;
    uint32_t i2 = 2;

    insert_value(hashMap, "first_key", &i1, L_INT);
    insert_value(hashMap, "first_key", &i2, L_INT);
//    insert_value(hashMap, "sda", &s1, L_STRING);
    
    print_hash_map(hashMap);
}
