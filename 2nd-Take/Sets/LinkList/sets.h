#ifndef SETS_H
#define SETS_H

/**
 * @file    sets.h
 * @brief   Implementation of a set data structure using linked lists.
 *
 * Detailed description:
 * This header file defines a dynamic set implementation where elements
 * are stored as nodes in a singly linked list. Each node holds an integer
 * member, and the set is always kept in sorted order to simplify operations
 * such as union, intersection, and difference.
 *
 * Unlike array-based sets, this implementation allows sets of arbitrary
 * size, limited only by available memory. The insert operation maintains
 * order, ensuring efficient traversal when performing set operations.
 *
 * Functions implemented:
 *  - initSET      : Initializes a set to empty.
 *  - makeNULL     : Clears all elements from a set.
 *  - insert       : Inserts an element in sorted order.
 *  - delete       : Removes an element from the set.
 *  - UNION        : Returns a new set containing elements from both sets.
 *  - INTERSECTION : Returns a new set containing only common elements.
 *  - DIFFERENCE   : Returns a new set containing elements in A but not in B.
 *  - display      : Prints the elements of a set with a label.
 *  - isMember      : Checks if an element exists in the set.
 *  - cardinality   : Returns the number of elements in the set.
 *
 * This implementation is useful for demonstrating set theory operations
 * using linked lists and ensuring unique, ordered membership.
 *
 * @author   Voltaire Ratilla
 * @date     Created: 23/09/2025
 * @date     Completed: 24/09/2025
*/

#define MAX 10

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int cardinality(SET A) {
    int count = 0;

    for (Node ap = A; ap != NULL; ap = ap->next)
    {
        count++;
    }
    

    return count;
}

bool isMember(SET A, int number) {
    for (Node ap = A; ap != NULL; ap = ap->next)
    {
        if (ap->member == number)
        {
            return true;
        }
        
    }
    

    return false;
}

void insert(SET* A, int number) {
    Node newNode = (Node) malloc(sizeof(struct node));

    if (newNode != NULL)
    {
        newNode->member = number;
        // newNode->next = *A;
        // *A = newNode;
        Node* trav = A;
        
        for (; *trav != NULL && (*trav)->member < number; trav = &(*trav)->next){}
        
        newNode->next = *trav;
        *trav = newNode;
    }
    
}

void delete(SET* A, int number) {
    Node* trav = A;

    for (; *trav != NULL && (*trav)->member != number; trav = &(*trav)->next){}

    if (*trav != NULL)
    {
        Node delNode = *trav;
        *trav = delNode->next;

        free(delNode);
    }
    
    
}

SET UNION(SET A, SET B) {
    SET U = NULL;

    Node ap = A, bp = B, *Uptr = &U;

    while (ap != NULL && bp != NULL)
    {
        *Uptr = malloc(sizeof(struct node));

        if (Uptr != NULL)
        {
            if (ap->member < bp->member)
            {
                (*Uptr)->member = ap->member;
                ap = ap->next;
            }
            else 
            {
                if (bp->member == ap->member) {
                    ap = ap->next;
                }
                
                (*Uptr)->member = bp->member;
                bp = bp->next;
            }
        }
        
        Uptr = &(*Uptr)->next;
    }

    if (bp != NULL)
    {
        ap = bp;
    }
    

    for (; ap != NULL; ap = ap->next)
    {
        *Uptr = malloc(sizeof(struct node));
        if (Uptr != NULL)
        {
            (*Uptr)->member = ap->member;
            Uptr = &(*Uptr)->next;
        }
        
    }

    *Uptr = NULL;

    return U;
}

SET INTERSECTION(SET A, SET B) {
    SET IN = NULL;
    Node ap = A, bp = B, *InPtr = &IN;

    while (ap != NULL && bp != NULL) {
        if (ap->member == bp->member) {
            *InPtr = malloc(sizeof(struct node));
            if (*InPtr != NULL) {
                (*InPtr)->member = ap->member;
                InPtr = &(*InPtr)->next;
            }
            ap = ap->next;
            bp = bp->next;
        } else if (ap->member < bp->member) {
            ap = ap->next;
        } else {
            bp = bp->next;
        }
    }

    *InPtr = NULL;
    return IN;
}

SET DIFFERENCE(SET A, SET B) {
    SET DIFF = NULL;
    Node ap = A, bp = B, *DiffPtr = &DIFF;

    while (ap != NULL && bp != NULL) {
        if (ap->member == bp->member) {
            ap = ap->next;
            bp = bp->next;
        } else if (ap->member < bp->member) {
            *DiffPtr = malloc(sizeof(struct node));
            if (*DiffPtr != NULL) {
                (*DiffPtr)->member = ap->member;
                DiffPtr = &(*DiffPtr)->next;
            }
            ap = ap->next;
        } else {
            bp = bp->next;
        }
    }

    // Add remaining elements of A
    while (ap != NULL) {
        *DiffPtr = malloc(sizeof(struct node));
        if (*DiffPtr != NULL) {
            (*DiffPtr)->member = ap->member;
            DiffPtr = &(*DiffPtr)->next;
        }
        ap = ap->next;
    }

    *DiffPtr = NULL;
    return DIFF;
}

void display(SET A, char setName) {
    Node trav = A;

    printf("SET %c = {", setName);
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