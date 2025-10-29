#ifndef SET_H
#define SET_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned int Set;

void initSet(Set* set) {
    *set = 0;
}

void insert(Set* set, int elem) {
    *set |= (1 << elem);
}

void deleteElem(Set* set, int elem) {
    *set &= ~(1 << elem);
}

Set UNION(Set a, Set b) {
    return a | b;
}

Set INTERSECTION(Set a, Set b) {
    return a & b;
}

Set DIFFERENCE(Set a, Set b) {
    return a & ~b;
}

Set SYMDIFFERENCE(Set a, Set b) {
    return a ^ b;
}

void display(Set set, char* label) {
    int mask = 1;

    printf("%-12s = ", label);
    for (int i = 0; i < 32; i++, mask <<= 1)
    {
        if (set & mask)
        {
            printf("%d ", i);
        }
        
    }
    printf("\n");
}

#endif