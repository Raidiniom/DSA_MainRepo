#ifndef CLDIH_h
#define CLDIH_h

#include <stdio.h>
#include <stdlib.h>

#define max 20

typedef enum {
    EMPTY,
    DELETE,
    OCCUPIED,
} Status;

typedef struct node {
    int element;
    Status status;
    struct node* next;
} *Node, SizeNode;

typedef Node Dictionary[max];

int hashFunct(int element) {
    if (element < 0) element = -element;
    return element % max;
}

void initDictionary(Dictionary dih) {
    for (int i = 0; i < max; i++)
    {
        dih[i] = NULL;
    }
    
}

void display(Dictionary dih, char* label) {
    printf("-----%24s------", label);

    for (int i = 0; i < max; i++)
    {
        printf("%d | ", i);
        if (dih[i] != NULL)
        {
            Node trav = dih[i];
            
            for (; trav != NULL; trav = trav->next)
            {
                printf("[ %d ]", trav->element);

                if (trav->next) printf(" -> ");
            }
        }
        else
        {
            printf("NULL");
            
        }
        printf("\n");
    }
    printf("\n");
}

#endif