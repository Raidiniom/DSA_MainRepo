#ifndef QUEUELINK_H
#define QUEUELINK_H

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
#include <string.h>
#include <stdbool.h>

typedef struct {
    char LName[16];
    char FName[24];
    char MI;
} persontype;

typedef struct node {
    persontype person;
    struct node* next;
} *Node;

typedef struct {
    Node front;
    Node rear;
} Queue;

// Hepler Functions
persontype createPerson(char* LName, char* FName, char MI) {
    persontype initialize;

    strcpy(initialize.LName, LName);
    strcpy(initialize.FName, FName);
    initialize.MI = MI;

    return initialize;
}

void displayPerson(persontype person) {
    printf("%-14s %c, %-12s\n", person.FName, person.MI, person.LName);
}

// Operations
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(Queue q) {
    return q.front == NULL;
}

// deleteFirst for dequeue, insertFirst for enqueue
bool enqueue(Queue* q, persontype person) {
    if(!isEmpty(*q)) {
        Node newNode = malloc(sizeof(struct node));

        if(newNode != NULL) {
            newNode->person = person;
            newNode->next = q->rear;
            q->rear = newNode;
            
        }
    }
}

#endif