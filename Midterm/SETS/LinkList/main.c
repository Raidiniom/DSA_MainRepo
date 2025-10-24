#include "set.h"

void main() {
    Set A;
    initSet(&A);

    insert(&A, 1);
    insert(&A, 2);
    insert(&A, 3);
    insert(&A, 4);
    insert(&A, 5);

    display(A, "A");

    deleteElem(&A, 3);

    display(A, "Delete A");

    // makeNull(&A);

    // display(A, "MakeNull A");

    printf("is 1 member? %-4s\n", (isMember(A, 1)) ? "Yes" : "No");
    printf("is 5 member? %-4s\n", (isMember(A, 5)) ? "Yes" : "No");
    printf("is 4 member? %-4s\n", (isMember(A, 4)) ? "Yes" : "No");
    printf("is 6 member? %-4s\n", (isMember(A, 6)) ? "Yes" : "No");

    printf("Cardinaly of Set A: %d\n", cardinality(A));
}