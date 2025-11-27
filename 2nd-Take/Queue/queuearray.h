#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

/**
 * @file    queuelink.h
 * @brief   Implementation of a queue data structure using linked lists.
 *
 * Detailed description:
 * This header file defines a queue implementation for storing and
 * managing `persontype` structures (last name, first name, and middle initial).
 * It provides the basic queue operations such as enqueue, dequeue, and display.
 *
 * The queue is implemented using an array list with front and rear
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
 * @date     Completed: 14/09/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    char LName[16];
    char FName[24];
    char MI;
} persontype;

typedef struct {
    persontype person[MAX];
    int front;
    int rear;
} Queue;

// Helper Functions
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
    q->front = 0;
    q->rear = 0;
}

bool isEmpty(Queue q) {
    return q.front == q.rear;
}

bool isFull(Queue q) {
    return q.rear == MAX;
}

persontype peek(Queue q) {
    return q.person[q.front];
}

bool enqueue(Queue* q, persontype person) {
    if (!isFull(*q))
    {
        q->person[q->rear] = person;
        q->rear++;

        return true;
    }

    return false;
}

bool dequeue(Queue* q) {
    if (!isEmpty(*q))
    {
        q->rear--;
        for (int i = 0; i < q->rear; i++)
        {
            q->person[i] = q->person[i + 1];
        }
        
        return true;
    }
    

    return false;
}

void debugQueue(Queue q, char* title) {
    printf("\n[DEBUG] %-20s\n", title);
    for (int i = q.front; i < q.rear; i++)
    {
        displayPerson(q.person[i]);
    }
    
}

void displayQueue(Queue* q) {
    Queue trav;
    initQueue(&trav);

    while (!isEmpty(*q))
    {
        displayPerson(peek((*q)));
        enqueue(&trav, peek((*q)));
        dequeue(q);
    }
    
    while (!isEmpty(trav))
    {
        enqueue(q, peek(trav));
        dequeue(&trav);
    }
}

#endif