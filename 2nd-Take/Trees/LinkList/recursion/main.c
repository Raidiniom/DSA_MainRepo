#include "tree.h"

void main() {
    Node myTree;
    initTree(&myTree);

    insertElem(&myTree, 6);
    insertElem(&myTree, 2);
    insertElem(&myTree, 7);
    insertElem(&myTree, 3);
    insertElem(&myTree, 1);
    insertElem(&myTree, 10);
    insertElem(&myTree, 3);
    insertElem(&myTree, 4);
    insertElem(&myTree, 9);
    insertElem(&myTree, 21);
    insertElem(&myTree, 5);

    printf("Initial Tree\n");
    postOrder(myTree);

    deleteElem(&myTree, 7);

    printf("\nDelete 1 elem in Tree\n");
    postOrder(myTree);

    makeNull(&myTree);

    printf("\nmakeNull Tree\n");
    postOrder(myTree);
}