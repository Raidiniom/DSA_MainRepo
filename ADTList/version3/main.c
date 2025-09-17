#include "adt.h"

void main() {
    ADTList mylist;
    initADTList(&mylist);

    insertFirst(&mylist, createProduct("Chair", 10));
    insertFirst(&mylist, createProduct("Table", 5));
    insertFirst(&mylist, createProduct("Ply-Wood", 60));
    insertFirst(&mylist, createProduct("CPU", 6));
    insertLast(&mylist, createProduct("Phone", 25));
    insertLast(&mylist, createProduct("Phone", 25));
    insertAt(&mylist, createProduct("CPU-RED", 4), 3);
    insertAt(&mylist, createProduct("GPU-GREEN", 20), 5);
    insertAt(&mylist, createProduct("Ballpen", 18), 7);

    displayList(mylist);

    printf("\nDeleting\n");

    deleteFirst(&mylist);
    deleteLast(&mylist);
    deleteAt(&mylist, 4);

    displayList(mylist);
    freeADTList(&mylist);
}