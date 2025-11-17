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

    printTree(myTree, 0);
    // printf("\nPost Order: ");
    // postOrder(myTree);

    // printf("\nPre Order: ");
    // preOrder(myTree);

    // printf("\nIn Order: ");
    // inOrder(myTree);

    // printf("\nnew insert 9 is a duplicate: %-8s\n", (duplicateData(myTree, 9)) ? "True" : "False");
    
    // int findNum;

    // printf("Enter number to find for: ");
    // scanf("%d", &findNum);

    // printf("is %d in the Tree: %-8s\n", findNum, (searchNode(myTree, findNum)) ? "Yes" : "No");
    
}