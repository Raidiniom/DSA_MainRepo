#include <stdio.h>

#include "bitset.h"

void main() {
    SET my, mx;
    initSET(&my);
    initSET(&mx);

    insert(&my, 0);
    insert(&my, 1);
    insert(&my, 2);
    insert(&my, 4);
    insert(&my, 5);

    insert(&mx, 3);
    insert(&mx, 1);
    insert(&mx, 2);
    insert(&mx, 5);
    insert(&mx, 7);


    displaySET(my);
    displaySET(mx);

    SET *B = DIFFERENCE(my, mx);
    displaySET((*B));
    // printf("is member %-10s", (isMember(my, 5) ? "yes" : "no"));
}   
