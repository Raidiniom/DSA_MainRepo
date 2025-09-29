#ifndef ADTLISTV2_H
#define ADTLISTV2_H

/**
 * @file adtlistv2.h
 * @brief Abstract Data Type (ADT) List - Array Implementation
 *
 * This header file defines the interface for an Array-based List ADT where list is a pointer pointing to a structure.
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
#include <string.h>

#define MAX_SIZE 50

typedef struct {
    char LName[16];
    char FName[24];
    char MI;
} Name;

typedef struct {
    Name name;
    char ID[16];
    char course[16];
} Student;

typedef struct {
    Student student[MAX_SIZE];
    int count;
} LIST;

Name create_name(char *LName, char *FName, char MI) {
    Name init_name;

    strcpy(init_name.LName, LName);
    strcpy(init_name.FName, FName);
    init_name.MI = MI;

    return init_name;
}

Student create_student(Name name, char *ID, char *course) {
    Student init_student;

    init_student.name = name;
    strcpy(init_student.ID, ID);
    strcpy(init_student.course, course);

    return init_student;
}

void initialize(LIST* list) {
    list->count = 0;
}

void makeNULL(LIST* list) {
    list->count = 0;
}

void insertLast(LIST* list, Student student) {
    list->student[list->count++] = student;
}

int locate(LIST list, char* ID) {
    int i = 0;

    for (; i < list.count && strcmp(list.student[i].ID, ID) != 0; i++){}
    
    return i + 1;
}

void delete(LIST* list, char* ID) {
    int pos = locate(*list, ID);

    for (int i = pos + 1; i < list->count; i++)
    {
        list->student[i - 1] = list->student[i];
    }
    
    list->count--;
}

void print_name(Name name) {
    printf("| %-12s%c, %-12s", name.FName, name.MI, name.LName);
}

void print_student(Student student) {
    print_name(student.name);
    printf("| %-12s| %-12s\n", student.ID, student.course);
}

void printList(LIST list) {
    printf("--------------------------------------------------\n");
    printf("| %-27s| %-12s| %-14s\n", "Name", "ID", "Course");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < list.count; i++)
    {
        print_student(list.student[i]);
    }
    printf("--------------------------------------------------\n");
}

#endif