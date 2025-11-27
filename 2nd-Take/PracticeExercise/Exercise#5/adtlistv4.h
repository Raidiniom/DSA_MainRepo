#ifndef ADTLISTV4_H
#define ADTLISTV4_H

/**
 * @file adtlistv2.h
 * @brief Abstract Data Type (ADT) List - Array Implementation
 *
 * This header file defines the interface for an Array-based List ADT where list is a pointer pointing to a structure.
 * while the strucure contains a pointer to an array.
 * 
 * Functions to be implemented:
 *  - insert     : Insert an element into the list
 *  - delete     : Remove an element from the list
 *  - locate     : Find the position of an element
 *  - retrieve   : Get the element at a given position
 *  - makeNull   : Reset the list to an empty state
 *  - printList  : Display the elements of the list
 * 
 * @author  Voltaire Ratilla
 * @date    Created: 26/08/2025
 * @date    Completed: --/--/----
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    char data;
} Element;

typedef struct node {
    Element* Elements; 
    int count;
} charList;

void initCharList(charList* list) {
    list->Elements = malloc(sizeof(Element) * MAX);
    list->count = 0;
}

void insertLast(charList* list, char elem) {
    if (list->count < MAX)
    {
        list->Elements[list->count++].data = elem;
    }
    
}

void insertAt(charList* list, char elem, int position) {
    if (list->count < MAX && position >= 0)
    {
        int idx = position - 1;
        list->count++;
        for (int i = list->count; i > idx; i--)
        {
            list->Elements[i].data = list->Elements[i - 1].data;
        }
        list->Elements[idx].data = elem;
    }
    
}

void displayLIST(charList* list) {
    for (int i = 0; i < list->count; i++)
    {
        printf("%c", list->Elements[i].data);
        
        if (i != list->count - 1)
        {
            printf(", ");
        }
        
    }
    
}

#endif