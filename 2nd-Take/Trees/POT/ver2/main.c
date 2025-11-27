#include "potlearn.h"

void main() {
    // Heap myHp;
    // initialize_HL(&myHp);

    // insertElem(&myHp, 7);
    // insertElem(&myHp, 1);
    // insertElem(&myHp, 5);
    // insertElem(&myHp, 9);
    // insertElem(&myHp, 0);
    // insertElem(&myHp, 2);
    // insertElem(&myHp, 6);
    // insertElem(&myHp, 3);

    // displayHL(myHp, "Init Heap");

    List mylst;
    initialize_HL(&mylst);

    insertList(&mylst, 10);
    insertList(&mylst, 1);
    insertList(&mylst, 6);
    insertList(&mylst, 9);
    insertList(&mylst, 3);
    insertList(&mylst, 2);
    insertList(&mylst, 7);

    displayHL(mylst, "This is List");
}