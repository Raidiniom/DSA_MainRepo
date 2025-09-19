#ifndef ARRSTACK_H
#define ARRSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct {
    char flavor[8];
    float weight;
} Chip;

typedef struct {
    Chip contents[MAX];
    int top;
} Can;

// Helper Functions
Chip createChip(char* flavor, float weigth) {
    Chip initialize;

    strcpy(initialize.flavor, flavor);
    initialize.weight = weigth;

    return initialize;
}

void displayChip(Chip chip) {
    printf("%-8s%.2f\n", chip.flavor, chip.weight);
}

// Operations
bool isEmpty(Can container) {
    return container.top == -1;
}

bool isFull(Can container) {
    return container.top == MAX - 1;
}

bool push(Can* container, Chip chip) {
    if (!isFull(*container))
    {
        container->contents[++container->top] = chip;
        return true;
    }
    return false;
}

bool pop(Can* container) {
    if (!isEmpty(*container))
    {
        container->top--;
        return true;
    }
    return false;
}

Chip top(Can container) {
    return container.contents[container.top];
}

void displayCan(Can* container) {
    Can temp = {.top = 0};

    while (!isEmpty(*container))
    {
        displayChip(top(*container));
        push(&temp, top(*container));
        pop(container);
    }
    
    while (!isEmpty(temp))
    {
        push(container, top(temp));
        pop(&temp);
    }
    
}

void displayAllCans(Can* containers) {
    for (int i = 0; i < 3; i++)
    {
        printf("Can #%d\n", i + 1);
        displayCan(&containers[i]);
        printf("\n");
    }
    
}

#endif