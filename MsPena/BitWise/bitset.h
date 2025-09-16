#ifndef BITSET_H
#define BITSET_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned char SET;

void initSET(SET* x) {
 *x = 0;
}

void insert(SET* x, int member) {
    if (member < (sizeof(char) * 8)) {
        unsigned char memberMask = 1 << member;

        *x = *x | memberMask;
    }
    else {
        printf("SET is full\n");
    }
    
}

void delete(SET* x, int member) {
    unsigned char memberMask = 1 << member;

    *x = *x & memberMask;
}

bool isMember(SET x, int member) {
    return x & (1 << member);
}

/*
UNION
INTERSECTION
DIFFERENCE
*/
SET* UNION(SET A, SET B) {
    SET* U = (SET*) malloc((sizeof(char) * 8));

    *U = A | B;

    return U;
}

SET* INTERSECTION(SET A, SET B) {
    SET* I = (SET*) malloc((sizeof(char) * 8));

    *I = A & B;

    return I;
}

SET* DIFFERENCE(SET A, SET B) {
    SET* D = (SET*) malloc((sizeof(char) * 8));

    *D = A & !B;

    return D;
}

void displaySET(SET x) {
    unsigned char mask = 1 << ((sizeof(char) * 8) - 1);

    while (mask != 0) {
        printf("%d ", (x & mask) ? 1 : 0);
        mask = mask >> 1;
    }

    printf("\n");
}

#endif