#include "tree.h"

void main() {
    Node myTree;
    initTree(&myTree);

    insertNode(&myTree, 5);
    insertNode(&myTree, 4);
    insertNode(&myTree, 7);
    insertNode(&myTree, 9);
    insertNode(&myTree, 6);
    insertNode(&myTree, 2);
    insertNode(&myTree, 3);
    insertNode(&myTree, 1);

    printf("Initial Tree\nRoot ------>\n");
    printTree(myTree, 0);

    deleteNode(&myTree, 4);

    printf("Delete one Node in Tree\n");
    printTree(myTree, 0);
}