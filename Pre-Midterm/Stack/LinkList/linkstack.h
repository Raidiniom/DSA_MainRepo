#ifndef LINKSTACK_H
#define LINKSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} *Node;

Node initList() {
    return NULL;
}

bool isEmpty(Node numlist) {
    return numlist == NULL;
}

void push(Node* numlist, int data) {
    Node newNode = (Node) malloc(sizeof(struct node));

    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->next = *numlist;
        *numlist = newNode;
    }
    
}

void pop(Node* numlist) {
    if (!isEmpty(*numlist))
    {
        Node delete = *numlist;
        *numlist = (*numlist)->next;
        free(delete);
    }
    
}

int top(Node numlist) {
    return numlist->data;
}

void pushSorted(Node* numlist, int data) {
    Node temp = initList();

    if (isEmpty(*numlist))
    {
        push(numlist, data);
    }
    else
    {
        // < desending order, > acsending order
        while (!isEmpty(*numlist) && data < top(*numlist))
        {   
            push(&temp, top(*numlist));
            pop(numlist);
        }
        
        push(numlist, data);

        // Return the original data
        while (!isEmpty(temp))
        {
            push(numlist, top(temp));
            pop(&temp);
        }
        
    }
    
}

void displayStack(Node* numlist) {
    Node temp = initList();

    while (!isEmpty(*numlist))
    {
        printf("%d\n", top(*numlist));
        push(&temp, top(*numlist));
        pop(numlist);
    }
    
    while (!isEmpty(temp))
    {
        push(numlist, top(temp));
        pop(&temp);
    }
    
}

#endif