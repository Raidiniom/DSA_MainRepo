#ifndef POTLEARN_H
#define POTLEARN_H

/**
 * @file    
 * @brief  
 *
 * Detailed description:
 * This is from Canvas DSA Practice Exercises in PQ
 * 
 * Functions to be implemented:
 *  - function   : Description
 *
 * @author   Voltaire Ratilla
 * @date     Created: DD/MM/YR
 * @date     Completed: DD/MM/YR
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int lastNdx;
} Heap, List;

void initialize_HL(Heap* hp) {
    hp->lastNdx = -1;
    for (int i = 0; i < MAX; i++)
    {
        hp->elem[i] = 255;
    }
    
}

void swap(int* pos1, int* pos2) {
    int hold = *pos1;
    *pos1 = *pos2;
    *pos2 = hold;
}

bool insertElem(Heap* hp, int elem) {
    if (hp->lastNdx + 1 >= MAX) return false;

    int childNdx = ++hp->lastNdx;
    int parentNdx = (childNdx - 1) / 2;

    hp->elem[childNdx] = elem;

    while (childNdx > 0 && hp->elem[childNdx] < hp->elem[parentNdx])
    {
        swap(&hp->elem[childNdx], &hp->elem[parentNdx]);

        childNdx = parentNdx;
        parentNdx = (childNdx - 1) / 2;
    }
    
    
    return true;
}

bool insertList(List* lst, int elem) {
    lst->elem[++lst->lastNdx] = elem;
}

void displayHL(Heap hp, char* label) {
    printf("%-16s:\n", label);

    for (int i = 0; i < hp.lastNdx; i++)
    {
        printf("%d", hp.elem[i]);

        if (i + 1 < hp.lastNdx)
        {
            printf(", ");
        }
        
    }
    
}

#endif