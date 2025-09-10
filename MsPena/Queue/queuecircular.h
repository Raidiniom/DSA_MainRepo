#ifndef QUEUECIRCULAR_H
#define QUEUECIRCULAR_H

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
    q->front = -1;
    q->rear = -1;
}

bool enqueue(Queue* q, persontype person) {
    if ((q->rear + 1) % MAX == q->front)
    {
        return false;
    }

    if (q->front == -1)
    {
        q->front = 0;
        q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % MAX;
    }

    q->person[q->rear] = person;
    return true;
    
}

void displayQueue(Queue q) {
    printf("Front = %d, Rear = %d\n", q.front, q.rear);
    if (q.front != -1)
    {
        int i = q.front;
        while (1)
        {
            displayPerson(q.person[i]);
            if (i == q.rear) break;
            i = (i + 1) % MAX;
        }
        
    }
    
    
}
#endif