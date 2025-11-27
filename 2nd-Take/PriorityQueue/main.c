#include "prioque.h"

void main() {
    Heap myHp;
    initHeap(&myHp);

    insert(&myHp, 6);
    insert(&myHp, 10);
    insert(&myHp, 5);
    insert(&myHp, 10);
    insert(&myHp, 2);
    insert(&myHp, 9);
    insert(&myHp, 7);
    insert(&myHp, 18);
    insert(&myHp, 4);
    insert(&myHp, 8);
    insert(&myHp, 3);
    
    debugDisplay(myHp, "Viewing Insertions");
    
    heapSort(&myHp);

    debugDisplay(myHp, "After heapSort");
}