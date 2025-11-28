#ifndef SET_H
#define SET_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

typedef int SET[MAX];

void initSet(SET set) {
    for (int i = 0; i < MAX; i++)
    {
        set[i] = 0;
    }
    
}

void insertMember(SET set, int member) {
    set[member] = 1;
}

void deleteMember(SET set, int member) {
    set[member] = 0;
}

SET* UNION(SET a, SET b) {
    SET* UN = calloc(sizeof(int), MAX);

    for (int i = 0; i < MAX; i++)
    {
        (*UN)[i] = a[i] | b[i];
    }

    return UN;
}

SET* DIFFERENCE(SET a, SET b) {
    SET* DI = calloc(sizeof(int), MAX);

    for (int i = 0; i < MAX; i++)
    {
        (*DI)[i] = a[i] & ~b[i];
    }

    return DI;
}

SET* SYMMETRIC_DIFFERENCE(SET a, SET b) {
    SET* SYDI = calloc(sizeof(int), MAX);

    for (int i = 0; i < MAX; i++)
    {
        (*SYDI)[i] = a[i] ^ b[i];
    }
    

    return SYDI;
}

SET* INTERSECTION(SET a, SET b) {
    SET* IN = calloc(sizeof(int), MAX);

    for (int i = 0; i < MAX; i++)
    {
        (*IN)[i] = a[i] & b[i];
    }
    

    return IN;
}

SET* COMPLEMENT(SET u, SET a) {
    SET* CO = calloc(sizeof(int), MAX);

    for (int i = 0; i < MAX; i++)
    {
        (*CO)[i] = u[i] & ~a[i];
    }
    

    return CO;
}

void displaySet(SET set, char* label) {
    printf("%6s = {", label);

    int first = 1;

    for (int i = 0; i < MAX; i++) {
        if (set[i] == 1) {

            if (!first) printf(", ");

            printf("%d", i);
            first = 0;
        }
    }
    printf("}\n");
}



#endif