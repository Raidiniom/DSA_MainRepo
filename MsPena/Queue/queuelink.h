#ifndef QUEUELINK_H
#define QUEUELINK_H

/**
 * @file    queuelink.h
 * @brief   Implementation of a queue data structure using linked lists.
 *
 * Detailed description:
 * This header file defines a queue implementation for storing and
 * managing `persontype` structures (last name, first name, and middle initial).
 * It provides the basic queue operations such as enqueue, dequeue, and display.
 *
 * The queue is implemented using a singly linked list with front and rear
 * pointers, and follows the FIFO (First In, First Out) principle. It also
 * includes helper functions to create and display `persontype` entries.
 *
 * Functions to be implemented:
 *  - initQueue   : Initializes the queue.
 *  - isEmpty     : Checks if the queue is empty.
 *  - enqueue     : Inserts a new person at the rear of the queue.
 *  - dequeue     : Removes a person from the front of the queue.
 *  - displayPerson: Displays the details of a person.
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