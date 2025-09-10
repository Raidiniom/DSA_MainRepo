#ifndef QUEUELINK_H
#define QUEUELINK_H

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