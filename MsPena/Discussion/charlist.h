#ifndef CHARLIST_H
#define CHARLIST_H

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    char elem[SIZE];
    int count;
} charList;

void initList(charList* L) {
    L->count = 0;
}

void insert(charList* L, char elem) {
    if (L->count < SIZE)
    {
        L->elem[L->count++] = elem;
    }
    else
    {
        printf("charList is full. Current count: %d\n", L->count);
    }

}

void delete(charList* L, char x) {
    int pos = 0;

    for (; pos < L->count && L->elem[pos] != x; pos++){}
    
    for (int i = pos+1; i < L->count; i++)
    {
        L->elem[i-1] = L->elem[i];
    }
    
    L->count--;
}

void deleteAll(charList* L, char x) {
    int a; // position holder

    // find position
    for (int i = 0; i < L->count; i++)
    {
        if (L->elem[i] == x) // If found get the position then stop the loop
        {
            printf("%c has been found will be delete!\n", L->elem[i]);
            for (int v = i; v != L->count - 1; v++)
            {
                L->elem[v] = L->elem[v + 1];
            }

            L->count--;
        }
        
    }
    
}

void displayCharList(charList L) {
    for (int i = 0; i != L.count; i++)
    {
        printf("%c ", L.elem[i]);
    }
    printf("\nCount: %d\n", L.count);
}

#endif