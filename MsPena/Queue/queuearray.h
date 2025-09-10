#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

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


#endif