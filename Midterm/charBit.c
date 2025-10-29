#include <stdio.h>
#include <stdlib.h>

typedef unsigned char SET;

/**
 * Least Significant Bit
 * Right to Left
 */
void printBits1(SET n) {
    for (int i = 0; i < 8; i++) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

/**
 * Most Significant Bit
 * Left to Right
 */
void printBits2(SET n) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

void displayLarge(SET n) {
    printf("Right to Left | ");
    printBits1(n);
    printf("Letf to Right | ");
    printBits2(n);
}

void insertElem(SET* n, int element) {
    *n |= (1 << element);
}

void reverseSET(SET* n) {
    SET temp = 0, val = *n;

    for (int i = 0; i < 8; ++i)
    {
        temp |= ((val >> i) & 1u) << (7 - i);
    }
    *n = temp;

}

void main() {
    SET test1 = 0;

    insertElem(&test1, 0);
    insertElem(&test1, 1);
    insertElem(&test1, 3);
    insertElem(&test1, 5);

    displayLarge(test1);

    reverseSET(&test1);
    
    displayLarge(test1);
}