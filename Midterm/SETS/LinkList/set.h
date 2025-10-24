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

Set UNION(Set a, Set b) {
    Set UN = NULL;

    Node travA = a, travB = b;

    while (travA != NULL && travB != NULL)
    {
        if (travA->member < travB->member)
        {
            insert(&UN, travA->member);
            travA = travA->next;
        }
        else if (travA->member > travB->member)
        {
            insert(&UN, travB->member);
            travB = travB->next;
        }
        else
        {
            insert(&UN, travA->member);
            travA = travA->next;
            travB = travB->next;
        }
    }

    if (travA == NULL)
    {
        travA = travB;
    }
    
    while (travA != NULL)
    {
        insert(&UN, travA->member);
        travA = travA->next;
    }
    
    return UN;
}

Set INTERSECTION(Set a, Set b) {
    Set IN = NULL;

    Node tra = a, trb = b;

    while (tra != NULL && trb != NULL)
    {
        if (tra->member == trb->member)
        {
            insert(&IN, tra->member);

            tra = tra->next;
            trb = trb->next;
        }
        else if (tra->member < trb->member)
        {
            tra = tra->next;
        }
        else
        {
            trb = trb->next;
        }
        
    }

    return IN;
}

Set DIFFERENCE(Set a, Set b) {
    Set DI = NULL;

    Node tra = a, trb = b;

    while (tra != NULL && trb != NULL)
    {
        if (tra->member == trb->member)
        {
            tra = tra->next;
            trb = trb->next;
        }
        else if (tra->member < trb->member)
        {
            insert(&DI, tra->member);
            tra = tra->next;
        }
        else
        {
            trb = trb->next;
        }

    }

    while (tra != NULL)
    {
        insert(&DI, tra->member);
        tra = tra->next;
    }
    

    return DI;
}

Set SYSMETRICDIFFERENCE(Set a, Set b) {
    Set SDI = NULL;

    Node tra = a, trb = b;

    while (tra != NULL && trb != NULL)
    {
        if (tra->member == trb->member)
        {
            tra = tra->next;
            trb = trb->next;
        }
        else if (tra->member < trb->member)
        {
            insert(&SDI, tra->member);
            tra = tra->next;
        }
        else
        {
            insert(&SDI, trb->member);
            trb = trb->next;
        }

    }

    if (tra == NULL)
    {
        tra = trb;
    }

    while (tra != NULL)
    {
        insert(&SDI, tra->member);
        tra = tra->next;
    }

    return SDI;
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
