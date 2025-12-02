#include "tree.h"

void main() {
    Node myTree;
    initTree(&myTree);

    insertElem(&myTree, 6);
    insertElem(&myTree, 2);
    insertElem(&myTree, 7);
    insertElem(&myTree, 1);
    insertElem(&myTree, 5);
    insertElem(&myTree, 3);

    printf("In Order: ");
    inOrder(myTree);
    printf("\nPre Order: ");
    preOrder(myTree);
    printf("\nPost Order: ");
    postOrder(myTree);
}