#ifndef SETS_H
#define SETS_H

/**
 * @file    sets.h
 * @brief   Implementation of basic set operations using arrays.
 *
 * Detailed description:
 * This header file defines a simple set data structure represented as
 * a fixed-size array (`SET`) where each index corresponds to an element,
 * and the value (0 or 1) indicates membership in the set. It provides
 * operations such as union, intersection, and difference to manipulate
 * sets, along with a display function to show the contents.
 *
 * This implementation is suitable for small-scale set operations where
 * elements are represented by integers within a fixed range (0–MAX-1).
 *
 * Functions to be implemented:
 *  - UNION        : Returns a set containing all elements from two sets.
 *  - INTERSECTION : Returns a set containing only common elements of two sets.
 *  - DIFFERENCE   : Returns a set containing elements in one set but not the other.
 *  - displaySet   : Prints all members of a given set with a label.
 *
 * @author   Voltaire Ratilla
 * @date     Created: 14/09/2025
 * @date     Completed: DD/MM/YYYY
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef int SET[MAX];

SET *UNION(SET A, SET B) {
    SET *U = calloc(MAX, sizeof(int));

    for (int i = 0; i < MAX; i++)
    {
        (*U)[i] = A[i] | B[i];
    }

    return U;
}

SET *INTERSECTION(SET A, SET B){
    SET *I = calloc(MAX, sizeof(int));

    for (int i = 0; i < MAX; i++)
    {
        (*I)[i] = A[i] & B[i];
    }

    return I;
}

SET *DIFFERENCE(SET A, SET B){
    SET *D = calloc(MAX, sizeof(int));

    for (int i = 0; i < MAX; i++)
    {
        (*D)[i] = A[i] & !B[i];
    }

    return D;
}

SET *SYSMETRIC_DIFFERENCE(SET A, SET B) {
    SET *SD = calloc(MAX, sizeof(int));

    for (int i = 0; i < MAX; i++)
    {
        (*SD)[i] = A[i] ^ B[i];
    }

    return SD;
}

/* TODO
    isEqual(A, B) → true if A and B contain exactly the same elements.
    Cardinality(A) → number of elements in the set.
*/

void displaySet(SET s, char setName) {
    printf("%c = {", setName);

    int first = 1;
    for (int i = 0; i < MAX; i++) {
        if (s[i] == 1) {
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