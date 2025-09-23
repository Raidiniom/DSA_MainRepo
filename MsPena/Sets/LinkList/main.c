#include "sets.h"

void main() {
    SET A, B, *C, *D;
    initSET(&A);
    initSET(&B);

    insert(&A, 9);
    insert(&A, 5);
    insert(&A, 3);
    insert(&A, 2);
    insert(&A, 1);

    insert(&B, 12);
    insert(&B, 6);
    insert(&B, 5);
    insert(&B, 4);
    insert(&B, 3);

    display(A, 'A');
    display(B, 'B');

    C = UNION(A, B);
    display((*C), 'C');

    D = INTERSECTION(A, B);
    display((*D), 'D');

    // printf("Testing makeNULL\n");
    // makeNULL(C);
    // display((*C), 'C');
    // delete(&A, 1);
    // delete(&A, 5);
    // delete(&A, 9);

    // printf("Testing Delete\n");
    // display(A, 'A');
}