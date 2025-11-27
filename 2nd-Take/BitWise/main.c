#include <stdio.h>

#include "bitset.h"

void main() {
    SET my, mx;
    initSET(&my);
    initSET(&mx);

    insert(&my, 0);
    insert(&my, 4);
    insert(&my, 6);
    insert(&my, 7);

    insert(&mx, 1);
    insert(&mx, 4);
    insert(&mx, 5);
    insert(&mx, 6);

    displaySET(my, "A");
    displaySET(mx, "B");

    SET B = UNION(my, mx);
    displaySET(B, "A u B");

    SET C = INTERSECTION(my, mx);
    displaySET(C, "A ^ B");

    SET D = DIFFERENCE(my, mx);
    displaySET(D, "A - B");

    printf("is 6 a member of set A: %-10s\n", (isMember(my, 6) ? "yes" : "no"));

    insert(&my, 4);
    insert(&mx, 3);

    printf("Insert 4 existing and insert 3 non-existing\n");
    displaySET(my, "A");
    displaySET(mx, "B");

    printf("Deleteing 3 from set B\n");
    delete(&mx, 3);
    displaySET(mx, "B");
}   
