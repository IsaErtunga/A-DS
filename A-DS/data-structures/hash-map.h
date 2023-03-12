//
//  hash-map.h
//  A-DS
//
//  Created by Isa Ertunga on 2023-02-26.
//

#ifndef hash_map_h
#define hash_map_h

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "linked-list.h"

#define HASH_MAP_SIZE 100

typedef struct HashKey {
    char* keyStr;
    List* values;
} HashKey;

/* Each key stores a pointer to a linked list */
typedef struct HashMap {
    struct HashKey* keys[HASH_MAP_SIZE];
    int size;
} HashMap;

HashMap* init_hash_map(void);
HashKey* init_hash_key(char* keyStr);

void insert_value(HashMap* hashMap, char* keyStr, void* value, uint8_t type);
void delete_value(void);
void get_value(void);

void print_hash_map(HashMap* hashMap);

unsigned long hash(unsigned char *str);

void clean_hash_map(void);

#endif /* hash_map_h */
