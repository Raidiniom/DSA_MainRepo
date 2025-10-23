#ifndef SET_H
#define SET_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef int Set[MAX];

Set* initSet() {
    Set* newSet =(Set*) calloc(MAX, sizeof(int));

    return newSet;
}

void makeNULL(Set* set) {
    for (int i = 0; i < MAX; i++)
    {
        (*set)[i] = 0;
    }
    
}

bool isMember(Set set, int findMember) {
    for (int i = 0; i < MAX; i++)
    {
        if (set[i] == findMember)
        {
            return true;
        }
        
    }
    
    return false;
}

int cardinality(Set set) {
    int count = 0;

    for (int i = 0; i < MAX; i++)
    {
        if (set[i]) count++;
    }

    return count;
}

void insert(Set* set, int member) {
    (*set)[member] = 1;
}

void deleteElem(Set* set, int member) {
    (*set)[member] = 0;
}

Set* UNION(Set A, Set B) {
    Set* U = initSet();

    for (int i = 0; i < MAX; i++)
    {
        (*U)[i] = A[i] | B[i];
    }

    return U;
}

Set* INTERSECTION(Set A, Set B) {
    Set* IN = initSet();

    for (int i = 0; i < MAX; i++)
    {
        (*IN)[i] = A[i] & B[i];
    }
    
    return IN;
}

/**
 * Can be used to get Set Complement by:
 * - Get the Union of Two Sets to use as Universal Set
 * - Put the Universal Set at set parameter A
 * - Put the Set to be complemented at set parameter B
 */
Set* DIFFERENCE(Set A, Set B) {
    Set* DI = initSet();

    for (int i = 0; i < MAX; i++)
    {
        (*DI)[i] = A[i] & ~B[i];
    }
    

    return DI;
}

Set* SYSMETRICDIFFERENCE(Set A, Set B) {
    Set* SD = initSet();

    for (int i = 0; i < MAX; i++)
    {
        (*SD)[i] = A[i] ^ B[i];
    }
    

    return SD;
}

void display(Set set, char* setName) {
    int flag = 1;
    printf("%6s = {", setName);
    for (int i = 0; i < MAX; i++)
    {
        if (set[i])
        {
            if (!flag) printf(", ");
            
            printf("%d", i);

            flag = 0;
        }
        
    }
    printf("}\n");
}

#endif