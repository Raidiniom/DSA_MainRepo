#include "sets.h"

void main() {
    SET A, B, *C, *D, *E;
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

    printf("SET A Cardinality: %d\n", cardinality(A));
    printf("is 6 a member of SET B? %-6s\n", (isMember(B, 6)) ? "Yes" : "No");

    // D = INTERSECTION(A, B);
    // display((*D), 'D');

    // E = DIFFERENCE(A, B);
    // display((*E), 'E');

    // printf("Testing makeNULL\n");
    // makeNULL(C);
    // display((*C), 'C');
    // delete(&A, 1);
    // delete(&A, 5);
    // delete(&A, 9);

    // printf("Testing Delete\n");
    // display(A, 'A');
}
