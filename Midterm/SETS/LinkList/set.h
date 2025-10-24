#ifndef SET_H
#define SET_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int member;
    struct node* next;
} *Node;

typedef Node Set;

void initSet(Set* set) {
    *set = NULL;
}

void makeNull(Set* set) {
    Node* trav = set;

    while (*trav != NULL)
    {
        Node delAll = *trav;
        *trav = delAll->next;
        free(delAll);
    }
    
}

void insert(Set* set, int member) {
    Node newNode =(Node) malloc(sizeof(struct node));
    Node* ins = set;
    
    for (; *ins != NULL && member > (*ins)->member; ins = &(*ins)->next){}
    
    if (newNode != NULL)
    {
        newNode->member =  member;
        newNode->next = *ins;
        *ins = newNode;
    }
    
}

void deleteElem(Set* set, int member) {
    Node* find = set;

    for (; *find != NULL && (*find)->member != member; find = &(*find)->next){}

    Node delEl = *find;
    *find = delEl->next;
    free(delEl);
}

bool isMember(Set set, int findMember) {
    Node search = set;

    for (; search != NULL; search = search->next)
    {
        if (search->member == findMember) 
        {
            return true;
        }
    }
    
    return false;
}

int cardinality(Set set) {
    int count = 0;
    Node counter = set;

    for (; counter != NULL; counter = counter->next, count++){}

    return count;
}

void display(Set set, char* setName) {
    if (set != NULL)
    {
        printf("%10s = {", setName);
        Set trav = set;

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
    else
    {
        printf("%10s Set is Empty\n", setName);
    }
    
    
}

#endif
