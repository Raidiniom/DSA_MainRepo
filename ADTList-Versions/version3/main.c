#include "adt.h"

void main() {
    ADTList mylist;
    initADTList(&mylist);

    printf("Initial List\n");
    insertFirst(&mylist, createProduct("Chair", 10));
    insertFirst(&mylist, createProduct("Table", 5));
    insertFirst(&mylist, createProduct("Ply-Wood", 60));
    insertFirst(&mylist, createProduct("CPU", 6));
    insertLast(&mylist, createProduct("Phone", 25));
    insertAt(&mylist, createProduct("CPU-RED", 4), 3);
    insertAt(&mylist, createProduct("Ply-Wood", 60), 4);
    insertAt(&mylist, createProduct("Ply-Wood", 60), 5);
    insertAt(&mylist, createProduct("GPU-GREEN", 20), 6);
    insertAt(&mylist, createProduct("Ballpen", 18), 7);
    insertLast(&mylist, createProduct("Ply-Wood", 60));

    insertMiddle(&mylist, createProduct("Reactive Armor", 500));

    displayList(mylist);

    printf("\nDeleting\n");

    // deleteFirst(&mylist);
    // deleteLast(&mylist);
    // deleteAt(&mylist, 4);

    deleteAllOccurence(&mylist, "Ply-Wood");

    displayList(mylist);
    freeADTList(&mylist);
}