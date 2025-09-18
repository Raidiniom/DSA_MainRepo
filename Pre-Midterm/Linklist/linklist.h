#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char name[24];
    float weight;
} Box;

typedef struct node {
    Box ofcontent;
    struct node* link;
} *Node;

// Helper Functions
Box createBox(char* name, float weight) {
    Box creating;

    strcpy(creating.name, name);
    creating.weight = weight;

    return creating;
}

void displayBox(Box box) {
    printf("%-16s%.2f Kg\n", box.name, box.weight);
}

// Operations
Node initList() {
    return NULL;
}

void insertFirst(Node* list, Box box) {
    Node newNode = (Node) malloc(sizeof(struct node));

    // This also works but better with type casting above
    // Node newNode = malloc(sizeof(struct node));
    
    if (newNode != NULL)
    {
        newNode->ofcontent = box;
        newNode->link = *list;
        *list = newNode;
    }
    
}

void insertLast(Node* list, Box box) {
    Node* last = list;

    for (; *last != NULL; last = &(*last)->link){}
    
    *last = malloc(sizeof(struct node));

    if (*last != NULL)
    {
        (*last)->ofcontent = box;
        (*last)->link =  NULL;
    }
    
}

void displayLinkList(Node list) {
    for (; list != NULL; list = list->link)
    {
        displayBox(list->ofcontent);
    }
    
}

#endif