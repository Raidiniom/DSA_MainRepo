#include "adt.h"

void main() {
    ADTList myList;
    initADTList(&myList);

    insertFirst(&myList, createProduct("Pencil", 25));
    insertFirst(&myList, createProduct("Paper", 10));
    insertFirst(&myList, createProduct("Pen", 15));
    insertFirst(&myList, createProduct("Pencil", 25));
    insertFirst(&myList, createProduct("Pencil", 25));
    insertMiddle(&myList, createProduct("Lava Bucket", 32));
    insertLast(&myList, createProduct("Eraser", 25));
    insertFirst(&myList, createProduct("Pencil", 25));
    insertAt(&myList, createProduct("Ruler", 21), 3);
    insertFirst(&myList, createProduct("Pencil", 25));

    displayList(myList);

    printf("==================\n");
    deleteFirst(&myList);
    deleteLast(&myList);
    deleteAt(&myList, 3);

    deleteAllOccur(&myList, "Pencil");

    displayList(myList);
}