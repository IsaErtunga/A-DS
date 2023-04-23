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
#include <string.h>

#include "../lists/linked_list_ptr.h"

#define HASH_MAP_SIZE 100

typedef struct KeyValue {
    char* key;
    int value;
} KeyValue;

/* Each key stores a pointer to a linked list */
typedef struct HashMap {
    struct PtrList* keys[HASH_MAP_SIZE];
    int size;
} HashMap;

/* INIT */
HashMap* init_hash_map(void);
KeyValue* create_key_value_pair(char* keyStr, int value);

/* OPERATIONS */
void insert_value(HashMap* hashMap, char* keyStr, int value);
void delete_value(void);
int int_get_value(HashMap* hashMap, char* key);

/* HASH */
unsigned long hash(unsigned char *str);

/* HELPERS */
int hash_list_search(PtrList* hashList, char* key);
void print_hash_map(HashMap* hashMap);
void int_clean_hash_map(HashMap* hashMap);

#endif /* hash_map_int_h */
