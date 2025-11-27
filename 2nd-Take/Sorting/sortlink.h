#ifndef SORTLINK_H
#define SORTLINK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char LName[16];
    char FName[24];
    char MI;
} nameType;

typedef struct node {
    int number;
    struct node* next;
} *Node;

// Helper Functions for the nameType
nameType createName(char* LName, char* FName, char MI) {
    nameType initialize;

    strcpy(initialize.LName, LName);
    strcpy(initialize.FName, FName);
    initialize.MI = MI;

    return initialize;
}

void printName(nameType name) {
    printf("%-12s %c, %-14s\n", name.FName, name.MI, name.LName);
}

// Normal Link List Operation
void initLinkList(Node* head) {
    *head = NULL;
}

void insertNode(Node* head, int number) {
    Node newNode = malloc(sizeof(struct node));

    if (newNode != NULL)
    {
        newNode->number = number;
        newNode->next = *head;
        *head = newNode;
    }
    
}

void printLinkList(Node head, char* title) {
    Node trav = head;

    printf("List Name: %-16s\n", title);
    for (; trav != NULL; trav = trav->next)
    {
        printf("%d", trav->number);
        if (trav->next != NULL)
        {
            printf(", ");
        }
        
    }
    printf("\n\n");
}

// Sorting Algorithms
void bubbleSort(Node* head) {
    int swapped;
    Node curr, last = NULL;
    do
    {
        swapped = 0;
        curr = *head;
        
        while (curr->next != last)
        {
            if (curr->number > curr->next->number)
            {
                int temp = curr->number;
                curr->number = curr->next->number;
                curr->next->number = temp;
                swapped = 1;
            }
            curr = curr->next;
        }
        last = curr;
    } while (swapped);
    
    printLinkList(*head, "Sorted List");
}

#endif