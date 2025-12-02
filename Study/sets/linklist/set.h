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
            if (atra->member < btra->member)
            {
                (*utra)->member = atra->member;
                atra = atra->link;
            }
            else
            {
                if (btra->member == atra->member) atra = atra->link;

                (*utra)->member = btra->member;
                btra = btra->link;
            }
            
        }
        
        utra = &(*utra)->link;
    }

    if (btra != NULL) atra = btra;

    for (; atra != NULL; atra = atra->link)
    {
        *utra = malloc(sizeof(Node));
        if (utra != NULL)
        {
            (*utra)->member = atra->member;
            utra = &(*utra)->link;
        }
        
    }

    *utra = NULL;
    return u;
}

Set INTERSECTION(Set a, Set b) {
    Set i = NULL;
    Node atra = a, btra = b, *itra = &i;

    while (atra != NULL && btra != NULL)
    {
        
        if (atra->member == btra->member)
        {
            *itra = malloc(sizeof(Node));
            if (*itra != NULL)
            {
                (*itra)->member = atra->member;
                itra = &(*itra)->link;
            }
            
            atra = atra->link;
            btra = btra->link;
        }
        else if (atra->member < btra->member)
        {
            atra = atra->link;
        }
        else
        {
            btra = btra->link;
        }
    
    }

    *itra = NULL;
    return i;
}

Set DIFFERENCE(Set a, Set b) {
    Set* d = NULL;
    Node atra = a, btra = b, *dtra = d;

    return d;
}

Set SYMMETRIC_DIFFERENCE(Set a, Set b) {
    // 
}

Set COMPLEMENT(Set universal, Set a) {
    // 
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