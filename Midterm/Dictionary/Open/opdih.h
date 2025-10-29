#ifndef OPDIH_h
#define OPDIH_h

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    int element;
    struct node* link;
} *Node, SizeNode;

typedef Node Dictionary[MAX];

int hashFunct(int element) {
    if (element < 0) element = -element;
    return element % MAX;
}

void initDictionary(Dictionary dih) {
    for (int i = 0; i < MAX; i++)
    {
        dih[i] = NULL;
    }
    
}

void insertElem(Dictionary dih, int element) {
    int index = hashFunct(element);
    Node newNode = (Node) malloc(sizeof(SizeNode));

    if (newNode != NULL) 
    {
        newNode->element = element;
        newNode->link = dih[index];
        dih[index] = newNode;
    }

}

void deleteElem(Dictionary dih, int element) {
    int index = hashFunct(element);
    Node* search = &dih[index];

    for (; *search != NULL && (*search)->element != element; search = &(*search)->link){}
    
    if (*search != NULL)
    {
        Node deleteHold = *search;
        *search = deleteHold->link;
        free(deleteHold);
    }
    
}

void display(Dictionary dih, char* label) {
    printf("----%-24s----\n", label);
    for (int i = 0; i < MAX; i++)
    {
        Node trav = dih[i];
        printf("%d | ", i);
        if (dih[i] == NULL)
        {
            printf("NULL");
        }
        else
        {

            for (; trav != NULL; trav = trav->link)
            {
                printf("[ %d ]", trav->element);

                if (trav->link)
                {
                    printf(" -> ");
                }
                
            }
            
        }
        printf("\n");
        
    }
    printf("\n");
}

#endif