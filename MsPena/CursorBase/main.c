#include <stdio.h>

#include "cursorbase.h"

void main() {
    VirtualHeap vh;
    initVirtualHeap(&vh);

    LIST l = -1;

    insertFront(&l, &vh, 'e');
    insertFront(&l, &vh, 'd');
    insertFront(&l, &vh, 'c');
    insertFront(&l, &vh, 'b');

    printf("\nInitial List\n");
    displayLIST(l, vh);

    insertLast(&l, &vh, 'x');
    insertLast(&l, &vh, 'y');
    insertLast(&l, &vh, 'z');

    
    insertSorted(&l, &vh, 'h');
    insertSorted(&l, &vh, 'a');

    printf("\nModified List\n");
    displayLIST(l, vh);

    deleteElem(&l, &vh, 'x');
    printf("\nDeleted 'x'\n");
    displayLIST(l, vh);
}