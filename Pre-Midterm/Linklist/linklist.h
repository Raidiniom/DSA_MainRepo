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
    printf("%-16s%.2f\n", box.name, box.weight);
}

// Operations
Node initList() {
    return NULL;
}

void insertFirst(Node* list, Box box) {
    Node newNode = (Node) malloc(sizeof(struct node));
    
    if (newNode != NULL)
    {
        newNode->ofcontent = box;
        newNode->link = *list;
        *list = newNode;
    }
    
}

void insertLast(Node* list, Box box) {
    Node *last = list;

    for (; *last != NULL; last = &(*last)->link){}
    
    *last = malloc(sizeof(struct node));

    if (*last != NULL)
    {
        (*last)->ofcontent = box;
        (*last)->link =  NULL;
    }
    
}

void insertAt(Node* list, Box box, int position) {
    Node *pos = list;
    int index = position - 1;
    for (int i = 0; *pos != NULL && i < index; pos = &(*pos)->link, i++){}

    Node newNode = (Node) malloc(sizeof(struct node));
    
    if (newNode != NULL)
    {
        newNode->ofcontent = box;
        newNode->link = (*pos)->link;
        (*pos)->link = newNode;
    }
    
}

void insertMiddle(Node* list, Box box) {
    Node* trav = list;
    Node* travfast = list;

    for (; *travfast != NULL && (*travfast)->link != NULL; travfast = &(*travfast)->link->link)
    {
        trav = &(*trav)->link;
    }

    Node newNode = (Node) malloc(sizeof(struct node));

    if (newNode != NULL)
    {
        newNode->ofcontent = box;
        newNode->link = (*trav)->link;
        (*trav)->link = newNode;
    }
    
}

void deleteFirst(Node* list) {
    Node delete = *list;
    *list = (*list)->link;
    free(delete);
}

void deleteLast(Node* list) {
    Node* travdel = list;

    for (; (*travdel)->link != NULL; travdel = &(*travdel)->link){}

    Node delete = *travdel;
    *travdel = NULL;

    free(delete);   
}

void deleteAt(Node* list, int position) {
    Node* travdel = list;
    
    int index = position - 1;

    for (int i = 0; *travdel != NULL && i < index; travdel = &(*travdel)->link, i++){}

    Node delete = *travdel;
    *travdel = (*travdel)->link;
    free(delete);
    
}

void displayLinkList(Node list) {
    printf("%-16s%-16s\n", "# Contents", "Weight in Kilos");
    for (int i = 0; list != NULL; list = list->link, i++)
    {
        printf("%d ", i + 1);
        displayBox(list->ofcontent);
    }
    
}

#endif