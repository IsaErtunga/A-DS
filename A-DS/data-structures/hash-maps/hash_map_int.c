//
//  hash_map_int.c
//  A-DS
//
//  Created by Isa Ertunga on 2023-02-26.
//

#include "hash_map_int.h"

HashMap* init_hash_map(void) {
    HashMap* newHashMap = (HashMap*)malloc(sizeof(HashMap));
    newHashMap->size = sizeof(newHashMap->keys) / sizeof(newHashMap->keys[0]);
    for (int i = 0; i < newHashMap->size; i++) {
        newHashMap->keys[i] = ptr_init_list();
    }
    return newHashMap;
}

KeyValue* create_key_value_pair(char* keyStr, int value) {
    KeyValue* newKeyValue = (KeyValue*)malloc(sizeof(KeyValue));
    newKeyValue->key = keyStr;
    newKeyValue->value = value;
    return newKeyValue;
}


void insert_value(HashMap* hashMap, char* keyStr, int value) {
    int hashIndex = (int)(hash((unsigned char*) keyStr) % hashMap->size);
    KeyValue* keyValue = create_key_value_pair(keyStr, value);
    ptr_append(hashMap->keys[hashIndex], keyValue);
}

void delete_value(void) {}

int int_get_value(HashMap* hashMap, char* key) {
    int hashIndex = (int)(hash((unsigned char*) key) % hashMap->size);
    PtrList* hashList = hashMap->keys[hashIndex];
    // TODO need optimized list search
    PtrListNode* traversePtr = hashList->head;
    int foundKey = -1;
    for (int i = 0; i < hashList->size; i++) {
        if (strcmp(((KeyValue*)traversePtr->value)->key, key) == 0) {
            foundKey = ((KeyValue*)traversePtr->value)->value;
        }
        traversePtr = traversePtr->next;
    }
    return foundKey;
}

void print_hash_map(HashMap* hashMap) {
    printf("{\n");
    for (int i = 0; i < hashMap->size; i++) {
        if (hashMap->keys[i]->size == 0) continue;
        
        PtrListNode* traversePtr = hashMap->keys[i]->head;
        while (traversePtr != NULL) {
            printf("\t'%s': %d\n",
                   ((KeyValue*)traversePtr->value)->key,
                   ((KeyValue*)traversePtr->value)->value);

            traversePtr = traversePtr->next;
        }
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
