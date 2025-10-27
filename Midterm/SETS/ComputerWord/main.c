#include "set.h"

void main() {
    Set A;
    initSet(&A);
    
    insert(&A, 2);
    insert(&A, 4);
    insert(&A, 6);
    insert(&A, 7);

    display(A, "Testing!!!");

    deleteElem(&A, 4);

    display(A, "Delete 4");
}