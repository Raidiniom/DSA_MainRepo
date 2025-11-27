#ifndef STACKLINKLIST_H
#define STACKLINKLIST_H

/**
 * @file    stacklinklist.h
 * @brief   Implementation of a stack data structure using linked lists.
 *
 * Detailed description:
 * This header file defines a stack implementation for storing and
 * managing `studType` records (student name, ID, and course). The stack
 * is dynamically allocated using a singly linked list, which allows for
 * flexible memory usage without a fixed maximum size.
 *
 * It provides the standard stack operations such as push, pop, and top,
 * along with helper functions to create and display student records.
 * Unlike an array-based stack, this version does not have a "full" state
 * unless system memory is exhausted.
 *
 * Functions to be implemented:
 *  - initList     : Initializes the stack as empty.
 *  - isEmpty      : Checks if the stack is empty.
 *  - isFull       : Indicates that a linked list stack does not get full.
 *  - push         : Adds a new student record onto the stack.
 *  - pop          : Removes the top student record from the stack.
 *  - popReturn    : Removes and returns the top student record.
 *  - top          : Displays the current top element.
 *  - displayStack : Prints all elements in the stack.
 *
 * @author   Voltaire Ratilla
 * @date     Created: 04/02/2025
 * @date     Completed: 04/02/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char FName[24];
    char LName[16];
    char MI;
} nameType;

typedef struct {
    nameType studName;
    int id;
    char course[8];
} studType;

typedef struct node {
    studType studRec;
    struct node* next;
} *Stack;

// Helper Functions
nameType createName(char* FName, char* LName, char MI) {
    nameType initialize;

    strcpy(initialize.FName, FName);
    strcpy(initialize.LName, LName);
    initialize.MI = MI;

    return initialize;
}

studType createStud(nameType studName, int id, char* course) {
    studType initialize;

    initialize.studName = studName;
    initialize.id = id;
    strcpy(initialize.course, course);

    return initialize;
}

void displayStud(studType studRec) {
    printf("%-10s%c %-16s - %d %-8s\n", 
        studRec.studName.FName, 
        studRec.studName.MI, 
        studRec.studName.LName,
        studRec.id,
        studRec.course);
}

// Operations
void initList(Stack* S) {
    *S = NULL;
}

bool isEmpty(Stack S) {
    return S == NULL;
}

bool isFull(Stack S) {
    printf("Link List does not get Full!\n");
}

bool push(Stack* S, studType student) {
    Stack newNode = malloc(sizeof(struct node));

    if (newNode != NULL)
    {
        newNode->studRec = student;
        newNode->next = *S;
        *S = newNode;
    }
    
}

bool pop(Stack* S) {
    if (!isEmpty(*S))
    {
        Stack delete = *S;
        *S = (*S)->next;
        free(delete);
        return true;
    }
    return false;
}

studType popReturn(Stack* S) {
    studType pr = {{"XXX", "XXX", 'X'}, -1, "XXX"};
    if (!isEmpty(*S))
    {
        Stack delete = *S;
        pr = delete->studRec;
        *S = (*S)->next;
        free(delete);
        return pr;
    }
    return pr;
}

void top(Stack S) {
    printf("\nTop data: ");
    displayStud(S->studRec);
}

void displayStack(Stack S) {
    if (!isEmpty(S))
    {
        Stack trav = S;

        for (; trav != NULL; trav = trav->next)
        {
            displayStud(trav->studRec);
        }
        
    }
    else
    {
        printf("Stack is Empty!\n");
    }
    
    
}

#endif