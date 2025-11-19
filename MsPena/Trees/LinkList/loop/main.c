#include "tree.h"

void main() {
    Node myTree;
    initTree(&myTree);

    insertElem(&myTree, 6);
    insertElem(&myTree, 1);
    insertElem(&myTree, 10);
    insertElem(&myTree, 3);
    insertElem(&myTree, 2);
    insertElem(&myTree, 4);
    insertElem(&myTree, 4);
    insertElem(&myTree, 9);
    insertElem(&myTree, 14);

    printf("Post Order: ");
    postOrder(myTree);

    deleteElem(&myTree, 3);
    deleteElem(&myTree, 10);

    printf("\n[After Delete] Post Order: ");
    postOrder(myTree);

    makeNull(&myTree);

    printf("\n[After makeNull] Post Order: ");
    postOrder(myTree);
}