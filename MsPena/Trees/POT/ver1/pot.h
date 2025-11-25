#ifndef POT_H
#define POT_H

/**
 * This header file code is shiet need to rework this
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int lastIdx;
    int oldLastIdx;
} Heap, List;

void initList(List* lst) {
    lst->lastIdx = 0;
    lst->oldLastIdx = 0;
    for (int i = 0; i < MAX; i++)
    {
        lst->elem[i] = 0;
    }
    
}

void swap(int* a, int* b) {
    int hold = *a;
    *a = *b;
    *b = hold;
}

void insertElem(List* lst, int elem) {
    if (lst->lastIdx == MAX)
    {
        printf("List is Full\n");
        return;
    }
    
    lst->elem[lst->lastIdx] = elem;
    int idx = lst->lastIdx;
    lst->lastIdx++;

    while (idx > 0 && lst->elem[(idx - 1) / 2] > lst->elem[idx])
    {
        swap(&lst->elem[idx], &lst->elem[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
    
    lst->oldLastIdx = lst->lastIdx;
}

void deleteMin(List* lst, int elem) {
    int elemIdx = -1;

    for (int i = 0; i < lst->lastIdx; i++)
    {
        if (lst->elem[i] == elem)
        {
            elemIdx = i;
            break;
        }
        
    }

    if (elemIdx == -1)
    {
        printf("Elem not found\n");
        return;
    }
    
    lst->elem[elemIdx] = lst->elem[lst->lastIdx - 1];
    lst->lastIdx--;

    while (1)
    {
        int left = 2 * elemIdx + 1;
        int right = 2 * elemIdx + 2;
        int smallest = elemIdx;

        if (left < lst->oldLastIdx && lst->elem[left] < lst->elem[smallest])
        {
            smallest = left;
        }

        if (right < lst->oldLastIdx && lst->elem[right] < lst->elem[smallest])
        {
            smallest = right;
        }
        
        if (smallest != elemIdx)
        {
            swap(&lst->elem[elemIdx], &lst->elem[smallest]);
            elemIdx = smallest;
        }
        else
        {
            break;
        }
        
    }
    
}

void sortedList(List* lst) {
    for (int i = 0; i < lst->lastIdx; i++)
    {
        deleteMin(lst, lst->elem[0]);
    }
    
}

void displayList(List lst) {
    for (int i = 0; i < lst.lastIdx; i++)
    {
        printf("%d", lst.elem[i]);

        if (i + 1 < lst.lastIdx)
        {
            printf(", ");
        }
        
    }
    printf("\n");
}

void displaySortedList(List lst) {
    for (int i = 0; i < lst.oldLastIdx; i++)
    {
        printf("%d", lst.elem[i]);

        if (i + 1 < lst.oldLastIdx)
        {
            printf(", ");
        }
        
    }
    printf("\n");
}

#endif