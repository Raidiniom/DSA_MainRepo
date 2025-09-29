#ifndef CLOSEDIH_H
#define CLOSEDIH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 20

typedef enum {empty, occupied, deleted} Status;

typedef struct {
    int data;
    Status status;
} Entry;

typedef Entry Dictionary[MAXSIZE];

// Operations
void initDictionary(Dictionary dih) {
    for (int i = 0; i < MAXSIZE; i++)
    {
        dih[i].data = 0;
        dih[i].status = empty;
    }
}

void display(Dictionary dih) {
    for (int i = 0; i < MAXSIZE; i++)
    {
        printf("[%d] | ", i);
        if (dih[i].status == empty)
        {
            printf("empty");
        }
        else if (dih[i].status == deleted)
        {
            printf("deleted");
        }
        else
        {
            printf("%d", dih[i].data);
        }
        printf("\n");
    }
    
}

#endif