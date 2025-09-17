#include "adt.h"

void main() {
    ADTList *myList;
    initADTList(&myList);

    insertFirst(&myList, createProduct("Paper", 10));
    insertFirst(&myList, createProduct("Pen", 15));
    insertFirst(&myList, createProduct("Pencil", 25));
    insertLast(&myList, createProduct("Eraser", 25));
    insertAt(&myList, createProduct("Ruler", 21), 3);

    displayList(*myList);
}