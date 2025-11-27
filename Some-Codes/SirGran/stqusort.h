#ifndef STQUSORT_H
#define STQUSORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 10

typedef struct 
{
    int ID;
    char name[16];
    int stock;
} Product;

typedef struct {
    Product prods[max];
} Stack;

typedef struct {
    Product prods[max];
    int front;
    int rear;
} Queue;

// Hepler Function
Product createProduct(int ID, char* name, int stock) {
    Product initialize;

    initialize.ID = ID;
    strcpy(initialize.name, name);
    initialize.stock = stock;

    return initialize;
}

void displayProduct(Product product) {
    printf("%d %-10s%d\n", product.ID, product.name, product.stock);
}

// Operations - Stack
void initStack(Stack* stack) {
    stack->prods[0] = createProduct(0, "Top", -1);
}

void push(Stack* stack, Product product) {
    stack->prods[++stack->prods[0].ID] = product;
}

void pop(Stack* stack) {
    stack->prods[0].ID--;
}

Product top(Stack stack) {
    return stack.prods[stack.prods[0].ID];
}

void debugStack(Stack stack) {
    printf("\n\n");
    for (int i = stack.prods[0].ID; i > 0; i--)
    {
        displayProduct(stack.prods[i]);
    }
    
}

// Operations - Queue
void initQueue(Queue* queue) {
    queue->front = 1;
    queue->rear = 0;
}

void enqueue(Queue* q, Product product) {
    if ((q->rear + 2) % max != q->front)
    {
        q->rear = (q->rear + 1) % max;
        q->prods[q->rear] = product;
    }
    
}

void dequeue(Queue* q) {
    if ((q->rear + 1) % max != q->front)
    {
        q->front = (q->front + 1) % max;
    }
    
}

Product peek(Queue queue) {
    return queue.prods[queue.front];
}

void debugQueue(Queue q) {
    printf("\n");
    for (int i = q.front; i != (q.rear + 1) % max; i = (i + 1) % max)
    {
        displayProduct(q.prods[i]);
    }
    
}

void insertSorted(Queue* q, Product product) {
    if ((q->rear + 2) % max != q->front)
    {
        Queue temp;
        initQueue(&temp);
        int insert = 0;

        while (((q->rear + 1) % max != q->front) && !insert)
        {
            if (peek(*q).stock < product.stock)
            {
                enqueue(&temp, peek(*q));
                dequeue(q);
            }
            else
            {
                enqueue(&temp, product);
                insert = 1;
            }
        }

        if (!insert)
        {
            enqueue(&temp, product);
        }

        while ((q->rear + 1) % max != q->front)
        {
            enqueue(&temp, peek(*q));
            dequeue(q);
        }
        
        while ((temp.rear + 1) % max != temp.front)
        {
            enqueue(q, peek(temp));
            dequeue(&temp);
        }
    }
    
}

void sortStackToQueue(Stack* s, Queue* q) {
    while (s->prods[0].ID > 0) {  // while stack not empty
        Product x = top(*s);
        pop(s);

        // If queue empty → just enqueue
        if ((q->rear + 1) % max == q->front) {
            enqueue(q, x);
            continue;
        }

        int moved = 0;
        int size = (q->rear - q->front + max) % max + 1;

        for (int i = 0; i < size; i++) {
            Product curr = peek(*q);
            dequeue(q);

            if (!moved && curr.stock > x.stock) {
                enqueue(q, x);   // insert in sorted order
                moved = 1;
            }
            enqueue(q, curr);    // put back
        }

        if (!moved) {
            enqueue(q, x); // biggest so far, goes last
        }
    }
}


#endif