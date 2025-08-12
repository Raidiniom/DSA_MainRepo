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

void delete(charList* L, char x) {
    int a; // position holder

    // find position
    for (int i = 0; i < L->count; i++)
    {
        if (L->elem[i] == x) // If found get the position then stop the loop
        {
            for (int v = i; v != L->count - 1; v++)
            {
                L->elem[v] = L->elem[v + 1];
            }

            L->count--;
            break;
        }
        
    }

    // Shifting values of the array
    
    
    
}

void displayCharList(charList L) {
    for (int i = 0; i < L.count; i++)
    {
        printf("%c ", L.elem[i]);
    }
    printf("\n");
}

#endif