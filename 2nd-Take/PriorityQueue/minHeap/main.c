#include "prqu.h"

void main() {
    List unli;
    initList(&unli);

    insertList(&unli, 6);
    insertList(&unli, 2);
    insertList(&unli, 5);
    insertList(&unli, 8);
    insertList(&unli, 1);
    insertList(&unli, 11);
    insertList(&unli, 9);
    insertList(&unli, 3);
    insertList(&unli, 10);
    insertList(&unli, 7);
    insertList(&unli, 4);
    insertList(&unli, 14);

    displayList(unli, "Unsorted List");

    Heap minHp;
    Initialize(&minHp);

    for (int i = 0; i < unli.count; i++)
    {
        insert(&minHp, unli.arr[i]);
    }
    
    displayHeap(minHp, "Min Heap");

    printf("count %d retainCount %d\n\n", minHp.count, minHp.retainCount);

    List fromDelete;
    initList(&fromDelete);

    printf("DeleteMin looped for all\n");
    for (int i = 0; i < minHp.retainCount; i++)
    {
        insertList(&fromDelete, Deletemin(&minHp));
    }
    
    displayList(fromDelete, "fromDelete List");
}