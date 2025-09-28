#ifndef OPENDIH_H
#define OPENDIH_H


#include <stdio.h>
#include <stdlib.h>
#include "../hash.h"

#define MAXSIZE 10

typedef struct node {
    int data;
    struct node* next;
} SizeNode, *Node;

typedef Node Dictionary[MAXSIZE];

// Operations
void initDictionary(Dictionary dih) {
    for (int i = 0; i < MAXSIZE; i++)
    {
        dih[i] = NULL;
    }
    
}

void insert(Dictionary dih, int data) {
    int index = onesPlaceHash(data);
    Node newNode = malloc(sizeof(SizeNode));

    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->next = dih[index];
        dih[index] = newNode;
    }
    
}

void delete(Dictionary dih, int data) {
    int index = onesPlaceHash(data);

    Node *dihPtr = &dih[index], delete;

    for (; *dihPtr != NULL && (*dihPtr)->data != data; dihPtr = &(*dihPtr)->next){}

    if (*dihPtr != NULL)
    {
        delete = *dihPtr;
        *dihPtr = delete->next;

        free(delete);
    }
    
    
}

void display(Dictionary dih) {
    for (int i = 0; i < MAXSIZE; i++)
    {
        printf("[%d] | ", i);
        Node trav = dih[i];

        for (; trav != NULL; trav = trav->next)
        {
            printf("%d", trav->data);

            if (trav->next != NULL)
            {
                printf(", ");
            }
            
        }
        printf("\n");
    }
    
}

#endif