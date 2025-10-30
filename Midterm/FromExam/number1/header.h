#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

int* BitVectorToArray(unsigned short word[]) {

    int* arr = malloc(sizeof(int) * 64);

    int index = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 15; j >= 0; j--)
        {
            arr[index++] = (word[i] >> j) & 1;
        }
        
    }

    return arr;
}

char* decode(int arr[]) {
    char* message = malloc(sizeof(char) * 9);

    int index = 0;
    for (int i = 0; i < 64; i += 8)
    {
        unsigned char charint = 0;
        
        for (int j = 0; j < 8; j++)
        {
            charint = (charint << 1) | arr[i + j];
        }
        
        message[index++] = charint;
    }
    message[index] = '\0';

    return message;
}

void displayPattern(int arr[]) {
    for (int i = 0; i < 64; i++)
    {
        printf("%d", arr[i]);

        if ((i + 1) % 8 == 0)
        {
            printf(" ");
        }
        
    }
    
    printf("\n");
}


#endif