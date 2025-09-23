#ifndef SETS_H
#define SETS_H

#define MAX 10

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int member;
    struct node* next;
} *Node;

typedef Node SET;

// Operations
void initSET(SET* A) {
    *A = NULL;
}

void makeNULL(SET* A) {
    while (*A != NULL)
    {
        Node delNode = *A;
        *A = (*A)->next;
        free(delNode);
    }
    
}

void insert(SET* A, int number) {
    Node newNode = (Node) malloc(sizeof(struct node));

    if (newNode != NULL)
    {
        newNode->member = number;
        // newNode->next = *A;
        // *A = newNode;

        // Code below will make the insert function into an insert sorted
        Node* trav = A;
        
        for (; *trav != NULL && (*trav)->member < number; trav = &(*trav)->next){}
        
        newNode->next = *trav;
        *trav = newNode;
    }
    
}

void delete(SET* A, int number) {
    Node* trav = A;

    for (; *trav != NULL && (*trav)->member != number; trav = &(*trav)->next){}

    Node delNode = *trav;
    *trav = delNode->next;

    free(delNode);
    
}

SET* UNION(SET A, SET B) {
    SET* U = malloc(sizeof(SET));
    initSET(U);

    Node ap = A, bp = B;

    while (ap != NULL && bp != NULL)
    {
        if (ap->member < bp->member)
        {
            insert(U, ap->member);
            ap = ap->next;
        }
        else if (bp->member < ap->member)
        {
            insert(U, bp->member);
            bp = bp->next;
        }
        else
        {
            insert(U, ap->member);
            ap = ap->next;
            bp = bp->next;
        }
        
    }

    for (; ap != NULL; ap = ap->next)
    {
        insert(U, ap->member);
    }

    for (; bp != NULL; bp = bp->next)
    {
        insert(U, bp->member);
    }

    return U;
}

SET* INTERSECTION(SET A, SET B) {
    SET* IN = malloc(sizeof(SET));
    initSET(IN);

    Node ap = A, bp = B;

    while (ap != NULL && bp != NULL)
    {
        if (ap->member == bp->member)
        {
            insert(IN, ap->member);
            ap = ap->next;
            bp = bp->next;
        }
        else if (ap->member < bp->member)
        {
            ap = ap->next;
        }
        else
        {
            bp = bp->next;
        }
    }

    return IN;
}


void display(SET A, char setName) {
    Node trav = A;

    printf("%c = {", setName);
    for (; trav != NULL; trav = trav->next)
    {
        printf("%d", trav->member);
        
        if (trav->next != NULL)
        {
            printf(", ");
        }
        
    }
    printf("}\n");
}

#endif