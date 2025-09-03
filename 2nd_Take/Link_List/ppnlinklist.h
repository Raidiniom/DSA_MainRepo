#ifndef PPNLINKLIST_H
#define PPNLINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char LName[16];
    char FName[24];
    char MI;
} nameType;

typedef struct {
    nameType name;
    char ID[16];
    char Course[8];
    int Year;
} studentType;

typedef struct node {
    studentType student;
    struct node* next;
} *LinkList;

// Helper Functions
nameType createNameType(char* LNanme, char* FName, char MI) {
    nameType initial;

    strcpy(initial.LName, LNanme);
    strcpy(initial.FName, FName);
    initial.MI = MI;

    return initial;
}

studentType createStudentType(nameType name, char* ID, char* Course, int Year) {
    studentType initial;

    initial.name = name;
    strcpy(initial.ID, ID);
    strcpy(initial.Course, Course);
    initial.Year = Year;

    return initial;
}

void displayName(nameType fullname) {
    printf("%-10s %c, %-10s", fullname.LName, fullname.MI, fullname.FName);
}

void displayStudent(studentType student) {
    displayName(student.name);
    printf("%-8s %-5s%d", student.ID, student.Course, student.Year);
}

// Link List Functions
void initLinkList(LinkList* head) {
    *head = NULL;
}

void insertFirst(LinkList* head, studentType student) {
    LinkList newNode = malloc(sizeof(struct node));

    if (newNode != NULL)
    {
        newNode->student = student;
        newNode->next = *head;
        *head = newNode;
    }
    
}

void insertLast(LinkList* head, studentType student) {
    LinkList *trav = head;

    for (; *trav != NULL; trav = &(*trav)->next){}
    
    *trav = malloc(sizeof(struct node));

    if (*trav != NULL)
    {
        (*trav)->student = student;
        (*trav)->next = NULL;
    }

}

void insertAt(LinkList* head, studentType student, int position) {
    LinkList *trav = head;

    for (int i = 1; *trav != NULL && i < position; i++, trav = &(*trav)->next){}

    LinkList newNode = malloc(sizeof(struct node));

    if (newNode != NULL)
    {
        newNode->student = student;
        newNode->next = *trav;
        *trav = newNode;
    }
 
}

void displayList(LinkList head) {
    LinkList trav = head;

    for (; trav != NULL; trav = trav->next)
    {
        displayStudent(trav->student);
        printf("\n");
    }
    
}

#endif