#include "set.h"

void main() {
    Set A, B;
    initSet(&A);
    initSet(&B);
    
    insert(&A, 2);
    insert(&A, 12); 
    insert(&A, 4);
    insert(&A, 6);
    insert(&A, 7);
    insert(&A, 9);
    insert(&A, 8);

    insert(&B, 2);
    insert(&B, 11); 
    insert(&B, 3);
    insert(&B, 6);
    insert(&B, 5);
    insert(&B, 8);

    display(A, "A");
    display(B, "B");

    Set UN = UNION(A,B);
    display(UN, "A U B");

    Set IN = INTERSECTION(A,B);
    display(IN, "A ^ B");

    Set DI = DIFFERENCE(A,B);
    display(DI, "A - B");

    Set SDI = SYMDIFFERENCE(A,B);
    display(SDI, "A triangle B");
}
