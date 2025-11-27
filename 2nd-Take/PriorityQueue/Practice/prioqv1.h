#ifndef PRIOQV1_H
#define PRIOQV1_H

#include <stdio.h>
#include <string.h>

#define MAXSIZE 20

typedef struct {
    char title[40];
    int prioNum;
} Ticket;

typedef struct {
    Ticket list[MAXSIZE];
    int lastNdx;
} PriorityQueue;

// Helper Functions
Ticket createTicket(char* title, int prioNum) {
    Ticket initTicket;

    strcpy(initTicket.title, title);
    initTicket.prioNum = prioNum;

    return initTicket;
}

void displayTicket(Ticket tk) {
    printf("%-40s- %d\n", tk.title, tk.prioNum);
}

// Operations
void initPriorityQueue(PriorityQueue* pq) {
    pq->lastNdx = -1;
}

Ticket peek(PriorityQueue pq) {
    return pq.list[0];
}

void swap(PriorityQueue* pq, int index1, int index2) {
    Ticket temp = pq->list[index1];
    pq->list[index1] = pq->list[index2];
    pq->list[index2] = temp;
}

void enqueue(PriorityQueue* pq, Ticket newTicket) {
    pq->list[++pq->lastNdx] = newTicket;

    int i = pq->lastNdx;
    int parent = (i - 1) / 2;

    while (i > 0 && pq->list[i].prioNum < pq->list[parent].prioNum)
    {
        swap(pq, i, parent);
        i = parent;
        parent = (i - 1) / 2;
    }
    
}

void heapify(PriorityQueue* pq, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left <= pq->lastNdx && pq->list[left].prioNum < pq->list[smallest].prioNum)
    {
        smallest = left;
    }
    
    if (right <= pq->lastNdx && pq->list[right].prioNum < pq->list[smallest].prioNum)
    {
        smallest = right;
    }

    if (smallest != index)
    {
        swap(pq, smallest, index);

        heapify(pq, smallest);
    }
    
}

void dequeue(PriorityQueue* pq) {
    pq->list[0] = pq->list[pq->lastNdx--];
    heapify(pq, 0);
}

void displayPQ(PriorityQueue pq, char* label) {
    printf("%-20s\n", label);

    for (int i = 0; i <= pq.lastNdx; i++)
    {
        displayTicket(pq.list[i]);
    }
    
}

#endif