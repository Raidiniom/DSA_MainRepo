#include <stdio.h>
#include <stdlib.h>


void printBits(unsigned int n, char* label) {
    printf("%-24s = ", label);
    unsigned int mask = 1u << (sizeof(unsigned int) * 8 - 1); // Start from the leftmost bit (MSB)

    for (; mask > 0; mask >>= 1) {
        putchar((n & mask) ? '1' : '0');
    }

    printf("\n");
}

void main() {
    unsigned int test = 0, reverseThis = 25, temp = reverseThis, t = 0;

    test |= 4;

    printf("[test] %u\n", test);
    printf("[reverseThis] %u\n", reverseThis);

    for (int i = 0; i < (int)(sizeof(unsigned int) * 8); i++)
    {
        t = (t << 1) | (temp & 1u);
        temp >>= 1;
    }
    temp = t;
    
    printf("[temp] %u\n", temp);

    printBits(test, "test");
    printBits(reverseThis, "reverseThis");
    printBits(temp, "temp");
}