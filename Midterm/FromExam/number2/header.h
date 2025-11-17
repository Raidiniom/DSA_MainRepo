#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define RESULT 3

typedef struct CacheEntry {
    char* key;
    char** result;        // array of RESULT null-terminated strings
    struct CacheEntry* next;
} CacheEntry;

typedef struct {
    CacheEntry* buckets[MAX];
} HASHTABLE;

/* initialize all buckets to NULL */
void initialize(HASHTABLE* table) {
    for (int i = 0; i < MAX; i++) {
        table->buckets[i] = NULL;
    }
}

/* simple string duplication (portable) */
static char* str_dup(const char* s) {
    if (!s) return NULL;
    size_t n = strlen(s) + 1;
    char* d = malloc(n);
    if (d) memcpy(d, s, n);
    return d;
}

/* djb2 string hash */
int hash(char* key) {
    unsigned long h = 5381;
    unsigned char *p = (unsigned char*)key;
    while (*p) {
        h = ((h << 5) + h) + *p; /* h * 33 + c */
        p++;
    }
    return (int)(h % MAX);
}

/* return pointer to result array for key or NULL if not cached */
char** lookup(HASHTABLE* table, char* key) {
    if (!table || !key) return NULL;
    int index = hash(key);
    CacheEntry* cur = table->buckets[index];
    while (cur) {
        if (strcmp(cur->key, key) == 0) return cur->result;
        cur = cur->next;
    }
    return NULL;
}

/* simulate a search result for key (allocates RESULT strings + array) */
static char** simulateSearchResults(const char* key) {
    char** res = malloc(sizeof(char*) * RESULT);
    if (!res) return NULL;
    for (int i = 0; i < RESULT; i++) {
        char buf[128];
        snprintf(buf, sizeof(buf), "%s - suggestion %d", key, i + 1);
        res[i] = str_dup(buf);
    }
    return res;
}

/* free a result array previously created by simulateSearchResults */
static void freeResults(char** results) {
    if (!results) return;
    for (int i = 0; i < RESULT; i++) {
        free(results[i]);
    }
    free(results);
}

/* insert key into hashtable with generated results; if key exists, update results */
void insert(HASHTABLE* table, char* key) {
    if (!table || !key) return;
    int index = hash(key);

    /* check existing entry */
    CacheEntry* cur = table->buckets[index];
    while (cur) {
        if (strcmp(cur->key, key) == 0) {
            /* update results */
            char** newres = simulateSearchResults(key);
            if (newres) {
                freeResults(cur->result);
                cur->result = newres;
            }
            return;
        }
        cur = cur->next;
    }

    /* create new entry and insert at head */
    CacheEntry* node = malloc(sizeof(CacheEntry));
    if (!node) return;
    node->key = str_dup(key);
    node->result = simulateSearchResults(key);
    node->next = table->buckets[index];
    table->buckets[index] = node;
}

/* remove a key from the table (if present) */
void removeKey(HASHTABLE* table, char* key) {
    if (!table || !key) return;
    int index = hash(key);
    CacheEntry** pcur = &table->buckets[index];
    while (*pcur) {
        if (strcmp((*pcur)->key, key) == 0) {
            CacheEntry* tofree = *pcur;
            *pcur = tofree->next;
            free(tofree->key);
            freeResults(tofree->result);
            free(tofree);
            return;
        }
        pcur = &(*pcur)->next;
    }
}

/* free entire hashtable */
void freeTable(HASHTABLE* table) {
    if (!table) return;
    for (int i = 0; i < MAX; i++) {
        CacheEntry* cur = table->buckets[i];
        while (cur) {
            CacheEntry* nxt = cur->next;
            free(cur->key);
            freeResults(cur->result);
            free(cur);
            cur = nxt;
        }
        table->buckets[i] = NULL;
    }
}

/* optional: display bucket contents (for debugging) */
void debugDisplay(HASHTABLE* table) {
    if (!table) return;
    for (int i = 0; i < MAX; i++) {
        CacheEntry* cur = table->buckets[i];
        if (!cur) continue;
        printf("[%d]", i);
        while (cur) {
            printf(" -> (%s)", cur->key);
            cur = cur->next;
        }
        putchar('\n');
    }
}

#endif