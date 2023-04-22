//
//  hash-map-tests.c
//  A-DS
//
//  Created by Isa Ertunga on 2023-03-12.
//

#include "hash-map-tests.h"


void hash_map_test(void) {
    HashMap* hashMap = init_hash_map();
    insert_value(hashMap, "123", 123);
    insert_value(hashMap, "123", 1234);
    insert_value(hashMap, "234", 234);
    print_hash_map(hashMap);
}
