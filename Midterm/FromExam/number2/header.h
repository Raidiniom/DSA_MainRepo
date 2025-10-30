#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct CacheEntry {
    char* key;
    char** result;
    struct CacheEntry* next;
} CacheEntry;

typedef struct {
    CacheEntry* buckets[MAX];
} HASHTABLE;

void initialize(HASHTABLE* table) {
    for (int i = 0; i < MAX; i++)
    {
        table->buckets[i] = NULL;
    }
    
}

#endif