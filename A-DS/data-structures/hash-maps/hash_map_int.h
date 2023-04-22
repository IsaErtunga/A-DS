//
//  hash_map_int.h
//  A-DS
//
//  Created by Isa Ertunga on 2023-02-26.
//

#ifndef hash_map_int_h
#define hash_map_int_h

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../lists/linked_list_int.h"

#define HASH_MAP_SIZE 100

typedef struct KeyValue {
    char* key;
    void* value;
    uint8_t valueType;
} KeyValue;

/* Each key stores a pointer to a linked list */
typedef struct HashMap {
    struct List* keys[HASH_MAP_SIZE];
    int size;
} HashMap;

HashMap* init_hash_map(void);
KeyValue* create_key_value_pair(char* keyStr, void* value, uint8_t valueType);

void insert_value(HashMap* hashMap, char* keyStr, void* value, uint8_t valueType);
//void delete_value(void);
void get_value(HashMap* hashMap, char* key);

void print_hash_map(HashMap* hashMap);

unsigned long hash(unsigned char *str);

void clean_hash_map(void);

#endif /* hash_map_int_h */