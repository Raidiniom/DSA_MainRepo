#ifndef STACKLINK_H
#define STACKLINK_H

/**
 * @file    stacklink.h
 * @brief   Implementation of a stack data structure using link list.
 *
 * Detailed description:
 * This header file defines a simple stack implementation for storing
 * and managing `persontype` structures (containing first name, last name,
 * and middle initial). It provides basic stack operations such as push,
 * pop, top, and display. 
 *
 * The stack is implemented using a link list and
 * follows the LIFO (Last In, First Out) principle. It also includes helper
 * functions to create and display `persontype` entries.
 *
 * Functions to be implemented:
 *  - initStack   : Initializes the stack.
 *  - makeNull    : Resets the stack to an empty state.
 *  - isEmpty     : Checks if the stack is empty.
 *  - isFull      : Checks if the stack is full.
 *  - push        : Adds a new person onto the stack.
 *  - pop         : Removes the top person from the stack.
 *  - top         : Displays the current top element.
 *  - displayStack: Prints all elements in the stack.
 *
 * @author   Voltaire Ratilla
 * @date     Created: 08/09/2025
 * @date     Completed: dd/mm/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char FName[24];
    char LName[16];
    char MI;
} persontype;

typedef struct node{
    persontype person;
    struct node* next;
} *Stack;

// Helper Functions
persontype createPerson(char* FName, char* LName, char MI) {
    persontype initailize;

    strcpy(initailize.FName, FName);
    strcpy(initailize.LName, LName);
    initailize.MI = MI;

    return initailize;
}

void displayPerson(persontype person) {
    printf("%-10s %c, %-12s\n", person.FName, person.MI, person.LName);
}

// Operations
void initStack(Stack* st) {
    *st = NULL;
}

bool isEmpty(Stack st) {
    return st == NULL;
}

bool isFull(Stack st) {
    printf("A Stack Link List does not have a limit!\nThus this will return false!");
    return false;
}

void makeNull(Stack* st) {
    if (!isEmpty(*st))
    {
        Stack delete;
        while (*st != NULL)
        {
            delete = *st;
            *st = (*st)->next;
            free(delete);
        }
        
        *st = NULL;
    }
    else
    {
        printf("Stack is already Empty!\n");
    }
    
}

bool push(Stack* st, persontype person) {
    Stack newNode = malloc(sizeof(struct node));

    if (newNode != NULL)
    {
        newNode->person = person;
        newNode->next = *st;
        *st = newNode;

        return true;
    }
    
    return false;
}

bool pop(Stack* st) {
    if (!isEmpty(*st))
    {
        Stack delete = *st;
        *st = (*st)->next;

        free(delete);

        return true;
    }
    
    return false;
}

bool top(Stack st) {
    if (!isEmpty(st))
    {
        displayPerson(st->person);

        return true;
    }
    else
    {
        printf("Stack is Empty!\n");

        return false;
    }
}

persontype peek(Stack st) {
    return st->person;
}

void debugStack(Stack st, char* title) {
    Stack trav = st;

    printf("\n[DEBUG] %-20s\n", title);
    for (; trav != NULL; trav = trav->next)
    {
        displayPerson(trav->person);
    }
    
}

void displayStack(Stack* st) {
    if (!isEmpty(*st))
    {
        Stack display;
        initStack(&display);

        while (!isEmpty(*st))
        {
            displayPerson(peek(*st));
            push(&display, peek(*st));
            pop(st);
        }
     
        while (!isEmpty(display))
        {
            push(st, peek(display));
            pop(&display);
        }
    }
    
}

#endif