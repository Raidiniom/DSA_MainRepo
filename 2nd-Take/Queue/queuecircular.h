#ifndef QUEUECIRCULAR_H
#define QUEUECIRCULAR_H

/**
 * @file    queuecircular.h
 * @brief   Implementation of a circular queue using arrays.
 *
 * Detailed description:
 * This header file defines a circular queue implementation for storing
 * and managing `persontype` structures (last name, first name, and middle initial).
 * The circular queue uses a fixed-size array and allows efficient use of space
 * by wrapping around when the end of the array is reached.
 *
 * It provides the standard queue operations such as enqueue, dequeue, peek,
 * and display. The queue follows the FIFO (First In, First Out) principle,
 * but unlike a simple array-based queue, it reuses freed positions to
 * optimize storage.
 *
 * Functions to be implemented:
 *  - initQueue    : Initializes the circular queue.
 *  - isEmpty      : Checks if the queue is empty.
 *  - isFull       : Checks if the queue is full.
 *  - enqueue      : Adds a new person to the rear of the queue.
 *  - dequeue      : Removes a person from the front of the queue.
 *  - peek         : Displays the front element without removing it.
 *  - displayQueue : Prints all elements in the queue in order.
 *
 * @author   Voltaire Ratilla
 * @date     Created: 08/09/2025
 * @date     Completed: 14/09/yyyy
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
    q->front = 1;
    q->rear = 0;
}

bool isEmpty(Queue q) {
    return (q.rear + 1) % MAX == q.front;
}

bool isFull(Queue q) {
    return (q.rear + 2) % MAX == q.front;
}

persontype peek(Queue q) {
    return q.person[q.front];
}

bool enqueue(Queue* q, persontype person) {
    if (!isFull(*q))
    {
        q->rear = (q->rear + 1) % MAX;
        q->person[q->rear] = person;

        return true;
    }
    
    return false;
}

bool dequeue(Queue* q) {
    if (!isEmpty(*q))
    {
        q->front = (q->front + 1) % MAX;

        return true;
    }
    

    return false;
}

void debugQueue(Queue q, char* title) {
    printf("\n[DEBUG] %-20s\n", title);

    for (int i = q.front; i != (q.rear + 1) % MAX; i = (i + 1) % MAX)
    {
        displayPerson(q.person[i]);
    }
    
}

void displayQueue(Queue* q) {
    Queue trav;
    initQueue(&trav);

    while (!isEmpty((*q)))
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