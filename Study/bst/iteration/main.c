#include "tree.h"

void main() {
    Node a;
    initTree(&a);

    insertData(&a, 7);
    insertData(&a, 2);
    insertData(&a, 9);
    insertData(&a, 5);
    insertData(&a, 1);
    insertData(&a, 4);
    insertData(&a, 8);
    insertData(&a, 3);

    rootCheck(a);

    printf("In Order: ");
    inOrder(a);
    printf("\nPre Order: ");
    preOrder(a);
    printf("\nPost Order: ");
    postOrder(a);

    deleteData(&a, 7);

    printf("\n[After Delete] In Order: ");
    inOrder(a);

    rootCheck(a);
}