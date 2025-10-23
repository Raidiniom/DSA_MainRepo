#include "set.h"

void main() {
    Set* A = initSet();
    Set* B = initSet();

    insert(A, 1);
    insert(A, 3);
    insert(A, 5);
    insert(A, 7);
    insert(A, 2);

    insert(B, 0);
    insert(B, 3);
    insert(B, 4);
    insert(B, 8);
    insert(B, 2);

    display(*A, "A");   
    display(*B, "B");

    Set* UN = UNION(*A, *B);
    display(*UN, "A U B");

    Set* IN = INTERSECTION(*A, *B);
    display(*IN, "A ^ B");

    Set* CO = DIFFERENCE(*UN, *A);
    display(*CO, "A'");

    Set* DI = DIFFERENCE(*A, *B);
    display(*DI, "A - B");

    Set* SYD = SYSMETRICDIFFERENCE(*A, *B);
    display(*SYD, "A triangle B");
}