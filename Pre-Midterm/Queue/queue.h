#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* link;
} *Node;

typedef struct {
    Node front;
    Node rear;
} Queue;

Queue initQ() {
    Queue initial;

    initial.front = NULL;
    initial.rear = NULL;

    return initial;
}

bool isEmpty(Queue q) {
    return q.front == NULL;
}

void enqueue(Queue* q, int data) {
    Node newNode = (Node) malloc(sizeof(struct node));

    newNode->data = data;
    newNode->link = NULL;

    if (q->front == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->link = newNode;
        q->rear = newNode;
    }

}

void dequeue(Queue* q) {
    Node delNode = q->front;
    q->front = q->front->link;
    free(delNode);
}

int peek(Queue q) {
    return q.front->data;
}

void enqueueSorted(Queue* q, int data) {
    Queue temp = initQ();

    if (isEmpty(*q))
    {
        enqueue(q, data);
    }
    else
    {
        while (!isEmpty(*q) && data < peek(*q))
        {
            enqueue(&temp, peek(*q));
            dequeue(q);
        }

        enqueue(&temp, data);

        while (!isEmpty(*q))
        {
            enqueue(&temp, peek(*q));
            dequeue(q);
        }

        *q = temp;
    }
    
}

void displayQueue(Queue* q) {
    Queue temp = initQ();

    while (!isEmpty(*q))
    {
        printf("%d", peek(*q));
        if (q->front->link != NULL)
        {
            printf(", ");
        }
        enqueue(&temp, peek(*q));
        dequeue(q);
    }

    *q = temp;
}

#endif