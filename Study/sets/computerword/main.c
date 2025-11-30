#include "set.h"

void main() {
    Set A;
    Set B;
    initSet(&A);
    initSet(&B);

    insertMember(&A, 1);
    insertMember(&A, 4);
    insertMember(&A, 9);
    insertMember(&A, 10);
    insertMember(&A, 2);
    insertMember(&A, 3);

    insertMember(&B, 7);
    insertMember(&B, 1);
    insertMember(&B, 6);
    insertMember(&B, 9);
    insertMember(&B, 11);
    insertMember(&B, 10);

    displaySet(A, "A");
    displaySet(B, "B");

    Set* UNI = UNION(A, B);
    displaySet(*UNI, "A v B");

    Set* INT = INTERSECTION(A, B);
    displaySet(*INT, "A ^ B");

    Set* DIFF = DIFFERENCE(A, B);
    displaySet(*DIFF, "A - B");

    Set* SYDI = SYMMETRIC_DIFFERENCE(A, B);
    displaySet(*SYDI, "A ^- B");

    Set* COM = COMPLEMENT(*UNI, A);
    displaySet(*COM, "A'");

    free(UNI);
    free(INT);
    free(DIFF);
    free(SYDI);
    free(COM);
}