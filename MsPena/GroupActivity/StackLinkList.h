#ifndef STACKLINKLIST_H
#define STACKLINKLIST_H

/**
 * @file    filename.h / filename.c
 * @brief   Short description of what this file does
 *
 * Detailed description:
 * - Explain the purpose of this file
 * - Mention if it’s part of a bigger project
 * - Include important details about usage/implementation
 *
 * Functions to be implemented:
 *  - function1 : Short description
 *  - function2 : Short description
 *  - function3 : Short description
 *
 * @author   Your Name
 * @date     Created: DD/MM/YYYY
 * @date     Completed: DD/MM/YYYY
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