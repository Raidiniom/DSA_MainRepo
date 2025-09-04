#ifndef STACKARRAY_h
#define STACKARRAY_h

/**
 * @file    stackarray.h
 * @brief   Implementation of a stack data structure using arrays.
 *
 * Detailed description:
 * This header file defines a simple stack implementation for storing
 * and managing `persontype` structures (containing first name, last name,
 * and middle initial). It provides basic stack operations such as push,
 * pop, top, and display. 
 *
 * The stack is implemented using a fixed-size array (`MAX` = 10) and
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
 * @date     Created: 04/09/2025
 * @date     Completed: 04/09/2025
 */


#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct {
    char FName[24];
    char LName[16];
    char MI;
} persontype;

typedef struct {
    persontype person[MAX];
    int top;
} Stack;

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
    st->top = -1;
}

void makeNull(Stack* st) {
    st->top = -1;
}

bool isEmpty(Stack st) {
    return st.top == -1;
}

bool isFull(Stack st) {
    return st.top >= MAX - 1;
}

bool push(Stack* st, persontype person) {
    if (!isFull(*st))
    {
        st->top++;
        st->person[st->top] = person;

        return true;
    }
    return false;
}

bool pop(Stack* st) {
    if (!isEmpty(*st))
    {
        st->top--;
        return true;
    }
    return false;
}

bool top(Stack st) {
    if (!isEmpty(st))
    {
        printf("[TOP] -> ");
        displayPerson(st.person[st.top]);
    }
    
}

void displayStack(Stack st) {
    if (!isEmpty(st))
    {
        for (int i = st.top; i > -1; i--)
        {
            displayPerson(st.person[i]);
        }
    }
    else
    {
        printf("Stack is Empty!");
    }
    
    
}

#endif