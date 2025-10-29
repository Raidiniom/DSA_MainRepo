#include <stdio.h>
#include <stdlib.h>

#define max 10

typedef int Array[max];

void initArray(Array dih) {
    for (int i = 0; i < max; i++)
    {
        dih[i] = 0;
    }
    
}

void insert(Array* dih, int number, int position) {
    if (position >= 0 && position <= max)
    {
        (*dih)[position] = number;
    }
    else
    {
        printf("%d is Out of bounds!\n", position);
    }
    
}

void display(Array dih) {
    for (int i = 0; i < max; i++)
    {
        printf("i | %d\n", dih[i]);
    }
    
}

void main(void) {
    Array myAr;
    initArray(myAr);

    insert(&myAr, 20, 0);
    insert(&myAr, 21, 1);
    insert(&myAr, 22, 3);
    insert(&myAr, 23, 5);
    insert(&myAr, 24, 7);
    insert(&myAr, 25, 9);
    insert(&myAr, 26, 11);

    display(myAr);
}