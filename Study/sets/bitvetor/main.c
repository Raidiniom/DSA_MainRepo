#include "set.h"

void main() {
    SET A, B;
    initSet(A);
    initSet(B);

    insertMember(A, 2);
    insertMember(A, 1);
    insertMember(A, 3);
    insertMember(A, 10);
    insertMember(A, 5);
    insertMember(A, 9);
    insertMember(A, 19);
    insertMember(A, 13);

    insertMember(B, 2);
    insertMember(B, 3);
    insertMember(B, 4);
    insertMember(B, 11);
    insertMember(B, 6);
    insertMember(B, 7);
    insertMember(B, 14);
    
    displaySet(A, "A");
    displaySet(B, "B");

    SET* universal = UNION(A, B);
    displaySet(*universal, "A v b");

    SET* DIF = DIFFERENCE(A, B);
    displaySet(*DIF, "A - b");

    SET* SYMDIF = SYMMETRIC_DIFFERENCE(A, B);
    displaySet(*SYMDIF, "A Δ B");

    SET* IN = INTERSECTION(A, B);
    displaySet(*IN, "A ^ B");

    SET* CO = COMPLEMENT(*universal, A);
    displaySet(*CO, "A'");
}