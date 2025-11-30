#ifndef SET_H
#define SET_H

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int Set;

void initSet(Set* s) {
    *s = 0;
}

void insertMember(Set* s, int member) {
    *s |= 1 << member;
}

void deleteMembe(Set* s, int member) {
    *s &= ~(1 << member);
}

Set* UNION(Set a, Set b) {
    Set* U = malloc(sizeof(Set));
    *U = a | b;
    return U;
}

Set* INTERSECTION(Set a, Set b) {
    Set* I = malloc(sizeof(Set));
    *I = a & b;
    return I;
}

Set* DIFFERENCE(Set a, Set b) {
    Set* D = malloc(sizeof(Set));
    *D = a & ~b;
    return D;
}

Set* SYMMETRIC_DIFFERENCE(Set a, Set b) {
    Set* SD = malloc(sizeof(Set));
    *SD = a ^ b;
    return SD;
}

Set* COMPLEMENT(Set universal, Set a) {
    Set* C = malloc(sizeof(Set));
    *C = universal & ~a;
    return C;
}

void displaySet(Set s, char* label) {
    printf("%8s = {", label);

    int first = 1;

    for (int i = 0; i < 32; i++) {
        if (s & (1 << i)) {
            if (!first) {
                printf(", ");
            }
            printf("%d", i);
            first = 0;
        }
    }

    printf("}\n");
}


#endif