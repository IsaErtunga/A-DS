//
//  hash-map.c
//  A-DS
//
//  Created by Isa Ertunga on 2023-02-26.
//

#include "hash-map.h"

HashMap* init_hash_map(void) {
    HashMap* newHashMap = (HashMap*)malloc(sizeof(HashMap));
    newHashMap->size = sizeof(newHashMap->keys)/sizeof(newHashMap->keys[0]);
    for (int i = 0; i < newHashMap->size; i++) {
        newHashMap->keys[i] = init_hash_key("-");
    }
    return newHashMap;
}

HashKey* init_hash_key(char* keyStr) {
    HashKey* newHashKey = (HashKey*)malloc(sizeof(HashKey));
    newHashKey->keyStr = keyStr;
    newHashKey->values = init_list();
    return newHashKey;
}

// TODO Fix
//void insert_value(HashMap* hashMap, char* keyStr, int value) {
//    int hashIndex = (int)(hash((unsigned char*) keyStr) % hashMap->size);
//    hashMap->keys[hashIndex]->keyStr = keyStr;
//    prepend(hashMap->keys[hashIndex]->values, value);
//}

void delete_value(void);
void get_value(void);



/* ------------ Helpers --------------*/
void print_hash_map(HashMap* hashMap) {
    printf("{\n");
    HashKey* traverseKeyPtr;
    for (int i = 0; i < hashMap->size; i++) {
        traverseKeyPtr = hashMap->keys[i];
        if (traverseKeyPtr->values->size == 0) continue; // Unused
        
        printf("\t[%s]:", traverseKeyPtr->keyStr);
        print_list(traverseKeyPtr->values);
    }
    
    printf("}\n");
}





/* ------------ djb2 Hash function --------------*/
// https://stackoverflow.com/questions/7666509/hash-function-for-string
unsigned long
hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
