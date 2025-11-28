#include "set.h"

void main() {
    Set A = createSet();
    Set B = createSet();

    insertMember(&A, 13);
    insertMember(&A, 1);
    insertMember(&A, 27);
    insertMember(&A, 8);
    insertMember(&A, 4);
    insertMember(&A, 10);

    insertMember(&B, 1);
    insertMember(&B, 2);
    insertMember(&B, 34);
    insertMember(&B, 8);
    insertMember(&B, 16);
    insertMember(&B, 6);
    insertMember(&B, 9);

    displaySet(A, "A");
    displaySet(B, "B");

    Set UNI = UNION(A, B);
    displaySet(UNI, "A v B");

    Set DIFF = DIFFERENCE(A, B);
    displaySet(DIFF, "A - B");

    Set SYMDIF = SYMMETRIC_DIFFERENCE(A, B);
    displaySet(SYMDIF, "A Δ B");

    Set INT = INTERSECTION(A, B);
    displaySet(INT, "A ^ B");

    Set COM = COMPLEMENT(UNI, A);
    displaySet(COM, "A'");
}