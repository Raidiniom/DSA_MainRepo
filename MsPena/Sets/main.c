#include <stdio.h>

#include "sets.h"

void main() {
    SET A = {1,1,0,0,1,0,0,1,0,0};
    SET B = {0,1,0,1,1,0,0,0,1,1};
    SET *C = UNION(A, B);
    SET *D = INTERSECTION(A, B);
    SET *E = DIFFERENCE(A, B);

    displaySet(A, 'A');
    displaySet(B, 'B');
    displaySet((*C), 'C');
    displaySet((*D), 'D');
    displaySet((*E), 'E');
}