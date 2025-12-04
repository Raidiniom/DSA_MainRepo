#include "tree.h"

void main() {
    Node a;
    initTree(&a);

    insertData(&a, 28);
    insertData(&a, 14);
    insertData(&a, 42);
    insertData(&a, 7);
    insertData(&a, 21);
    insertData(&a, 35);
    insertData(&a, 49);
    insertData(&a, 3);
    insertData(&a, 10);
    insertData(&a, 17);
    insertData(&a, 24);
    insertData(&a, 31);
    insertData(&a, 38);
    insertData(&a, 45);
    insertData(&a, 52);

    printf("In Order: ");
    inOrder(a);
    printf("\nPre Order: ");
    preOrder(a);
    printf("\nPost Order: ");
    postOrder(a);
}