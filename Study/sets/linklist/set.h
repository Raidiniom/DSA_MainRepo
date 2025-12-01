#ifndef SET_H
#define SET_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int member;
    struct node* link;
} *Node;

typedef Node Set;

void initSet(Set* s) {
    *s = NULL;
}

void insertMember(Set* s, int member) {
    Node newNode = malloc(sizeof(Node));

    if (newNode != NULL)
    {
        newNode->member = member;
        Node* trav = s;
        for (; *trav != NULL && (*trav)->member < member; trav = &(*trav)->link){}

        newNode->link = *trav;
        *trav = newNode;
    }
    
}

void deleteMember(Set* s, int member) {
    if (*s != NULL)
    {
        Node* trav = s;
        for (; *trav != NULL && (*trav)->member != member; trav = &(*trav)->link){}

        if (*trav != NULL)
        {
            Node del = *trav;
            *trav = del->link;
            
            free(del);
        }
        
    }
    
}

Set UNION(Set a, Set b) {
    Set u = NULL;
    Node atra = a, btra = b, *utra = &u;

    while (atra != NULL && btra != NULL)
    {
        *utra = malloc(sizeof(Node));

        if (*utra != NULL)
        {
            /* code */
        }
        
        utra = &(*utra)->link;
    }
    

    return u;
}

void displaySet(Set s, char* label) {
    Node trav = s;

    printf("%-8s = {");
    for (; trav != NULL; trav = trav->link)
    {
        printf("%d", trav->member);

        if (trav->link != NULL) printf(", ");
    }
    printf("}\n");
}   

#endif