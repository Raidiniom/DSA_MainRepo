#ifndef BITSET_H
#define BITSET_H

/**
 * @file    bitset.h
 * @brief   Implementation of a set data structure using bit manipulation.
 *
 * Detailed description:
 * This header file defines a compact set representation using an
 * `unsigned char` where each bit corresponds to a possible element
 * (0–7 on most systems since `char` is 8 bits). It provides fundamental
 * set operations such as insertion, deletion, membership checking,
 * union, intersection, and difference.
 *
 * The bitset approach allows efficient storage and manipulation
 * of small sets, making operations very fast compared to array-based
 * implementations. Helper functions are also provided to initialize
 * and display sets in binary form.
 *
 * Functions implemented:
 *  - initSET       : Initializes a set to empty.
 *  - insert        : Adds an element to the set.
 *  - delete        : Removes an element from the set.
 *  - isMember      : Checks if an element belongs to the set.
 *  - UNION         : Computes the union of two sets.
 *  - INTERSECTION  : Computes the intersection of two sets.
 *  - DIFFERENCE    : Computes the difference of two sets.
 *  - displaySET    : Displays the set as a sequence of bits.
 *
 * @author   Voltaire Ratilla
 * @date     Created: 16/09/2025
 * @date     Completed: 16/09/2025
*/

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

    *x = *x & (~memberMask);
}

bool isMember(SET x, int member) {
    return x & (1 << member);
}

SET UNION(SET A, SET B) {
    return A | B;
}

SET INTERSECTION(SET A, SET B) {
    return A & B;
}

SET DIFFERENCE(SET A, SET B) {
    return A & ~B;
}

void displaySET(SET x, char* label) {
    unsigned char mask = 1;

    printf("%-6s= {", label);

    for (int i = 0; mask != 0; i++) {
        if (x & mask) {
            printf("%d", i);

            unsigned char rest = x & (~((mask << 1) - 1));
            if (rest != 0) {
                printf(", ");
            }
        }
        mask = mask << 1;
    }

    printf("}\n");
}


#endif