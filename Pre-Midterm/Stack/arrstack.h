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

void pushContainer(Can* container, Chip chip) {
    for (int i = 0; i < 3; i++)
    {
        if (!isFull(container[i]))
        {
            push(&container[i], chip);
            printf("Pushed %s %.2f into Can #%d\n", chip.flavor, chip.weight, i + 1);
            return;
        }
        
    }
    
}

void popContainer(Can* container) {
    for (int i = 2; i >= 0; i--)
    {
        if (!isEmpty(container[i]))
        {
            pop(&container[i]);
            printf("Pop from Container #%d\n",i);
            return;
        }
        
    }
    
}

char* flavorChoice() {
    int fc;
    printf("Choose Flavor:\n0 - Vanilla\n1 - Spicy\n2 - Mustard\n");
    scanf("%d", &fc);
    switch (fc)
    {
    case 0:
        return "Vanilla";
        break;

    case 1:
        return "Spicy";
        break;

    case 2:
        return "Mustard";
        break;
    
    default:
        printf("Not One of the Options!\n");
        return "Null";
        break;
    }
}

float weightChoice() {
    float wc;
    printf("Enter chip weight: ");
    scanf("%f", &wc);
    return wc;
}

void displayCan(Can* container) {
    Can temp = {.top = -1};

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

void displayMenu() {
    printf("Stack Operations:\n0 - Push\n1 - Pop\n2 - Open Container\n3 - Stop Program\n");
}

#endif