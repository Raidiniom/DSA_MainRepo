#include <stdio.h>

#include "cursorbase.h"

void main() {
    VirtualHeap vh;
    initVirtualHeap(&vh);

    LIST l = -1;

    insertFront(&l, &vh, 'a');
    insertFront(&l, &vh, 'b');
    insertFront(&l, &vh, 'c');
    insertFront(&l, &vh, 'd');

    displayLIST(l, vh);

    insertLast(&l, &vh, 'x');

    displayLIST(l, vh);
}