#include "set.h"

void main() {
    Set A, B;
    initSet(&A);
    initSet(&B);

    insert(&A, 1);
    insert(&A, 4);
    insert(&A, 6);
    insert(&A, 3);
    insert(&A, 11);
    insert(&A, 8);
    insert(&A, 5);

    insert(&B, 0);
    insert(&B, 4);
    insert(&B, 6);
    insert(&B, 2);
    insert(&B, 11);
    insert(&B, 7);
    insert(&B, 9);

    display(A, "A");
    display(B, "B");

    Set UN = UNION(A, B);
    display(UN, "A U B");

    Set IN = INTERSECTION(A, B);
    display(IN, "A ^ B");

    Set DI = DIFFERENCE(A, B);
    display(DI, "A - B");

    Set SDI = SYSMETRICDIFFERENCE(A, B);
    display(SDI, "A TRIANGLE B");
}