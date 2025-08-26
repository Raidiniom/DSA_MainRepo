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

#endif