#include "set.h"

void main() {
    Set a, b;
    initSet(&a);
    initSet(&b);

    insertMember(&a, 1);
    insertMember(&a, 2);
    insertMember(&a, 3);
    insertMember(&a, 6);
    insertMember(&a, 4);

    insertMember(&b, 1);
    insertMember(&b, 4);
    insertMember(&b, 2);
    insertMember(&b, 5);

    displaySet(a, "A");
    displaySet(b, "B");

    Set universal = UNION(a, b);
    displaySet(universal, "A v B");

    Set intersection = INTERSECTION(a, b);
    displaySet(intersection, "A ^ B");
}