#ifndef FUNCTION_H
#define FUNCTION_H

/**
 * @file    function.h 
 * @brief   Array-based implementation of a List Abstract Data Type (ADT).
 *
 * This file defines the interface for an Array-based List ADT where the list 
 * is managed as a pointer to a structure. It provides a set of operations 
 * for inserting, deleting, retrieving, and separating elements within the list. 
 * The ADT ensures modularity and reusability, making it suitable for academic 
 * exercises, learning data structures, or as part of a larger project requiring 
 * dynamic list manipulation.
 *
 * Functions to be implemented:
 *  - insertFirst : insert the given element at the first position of the given list.
 *  - insertLast : insert the given element at the last position of the given list.
 *  - insertLastUnique : insert the given element at the last position of the given list if the element does not yet exist. 
                        - Elements are uniquely identified through the ID.
 *  - insertAtPosition : insert a given element at the valid position in the given list.
                        - Note: The position is integral and may not always be valid.
 *  - deleteElem : delete the element with the given ID in the list.
                        - The deleted element will be returned to the calling function.
                        - If no element is deleted, return a dummy variable containing:
                            "XXXXX" for strings
                            'X' for characters
                            0 for integers
 *  - separateCourse :  remove from the given list all elements bearing the specified course and put them in a new list, which will be returned to the calling function.
 *
 * @author   Voltaire Ratilla
 * @date     Created: 27/08/2025
 * @date     Completed: DD/MM/YYYY
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

typedef struct {
    char FN[24];
    char MI;
    char LN[16];
} nameType;

typedef struct {
    nameType name;
    char ID[16];
    char course[16];
    int yearLevel;
} studentType;

typedef struct {
    studentType stud[MAX_SIZE];
    int count;
} ArrayList;

typedef struct node {
    studentType stud;
    struct node* next;
} *LinkList;

nameType createNameType(char* FN, char MI, char* LN) {
    nameType initialize;

    strcpy(initialize.FN, FN);
    initialize.MI = MI;
    strcpy(initialize.LN, LN);

    return initialize;
}

studentType createStudentType(nameType fullname, char* ID, char* course, int yearLevel) {
    studentType initialize;

    initialize.name = fullname;
    strcpy(initialize.ID, ID);
    strcpy(initialize.course, course);
    initialize.yearLevel = yearLevel;

    return initialize;
}

// ArrayList
void initArrayList(ArrayList* arrylst) {
    arrylst->count = 0;
}

void insertFront(ArrayList* arrylst, studentType student) {
    for (int i = arrylst->count; i > 0 ; i--)
    {
        arrylst->stud[i] = arrylst->stud[i - 1];
    }
    arrylst->count++;
    arrylst->stud[0] = student;
}

void insertLast(ArrayList* arrylst, studentType student) {
    arrylst->stud[arrylst->count++] = student;
}

void insertLastUnique(ArrayList* arrylst, studentType student) {
    int i = arrylst->count;

    for (; i > 0 && strcmp(arrylst->stud[i].ID, student.ID) != 0; i--){}

    if (i == 0)
    {
        arrylst->stud[arrylst->count++] = student;
    }
    
    
}

void insertAtPosition(ArrayList* arrylst, studentType student, int position) {
    for (int i = arrylst->count; i > position ; i--)
    {
        arrylst->stud[i] = arrylst->stud[i - 1];
    }
    arrylst->count++;
    arrylst->stud[position - 1] = student;
}

studentType deleteElem(ArrayList* arrylst, char* ID) {
    studentType delete = createStudentType(createNameType("XXXXXX", 'X', "XXXXXX"), "XXXXXX", "XXXXXX", 0);

    int i = arrylst->count - 1;

    for (; i >= 0 && strcmp(arrylst->stud[i].ID, ID) != 0; i--){}
    
    if (i >= 0)
    {
        delete = arrylst->stud[i];

        for (int x = i + 1; x < arrylst->count; x++)
        {
            arrylst->stud[x - 1] = arrylst->stud[x];
        }
        arrylst->count--;
    }

    return delete;
}

ArrayList separateCourse(ArrayList* arrylst, char* course) {
    ArrayList separate;
    initArrayList(&separate);

    for (int i = arrylst->count - 1; i >= 0; i--)
    {
        if (strcmp(arrylst->stud[i].course, course) == 0)
        {
            insertLast(&separate, deleteElem(arrylst, arrylst->stud[i].ID));
        }
        
    }
    

    return separate;
}
// ============================================================

// LinkList

// ============================================================

void displayName(nameType fullname) {
    printf("%-10s %c, %-10s", fullname.FN, fullname.MI, fullname.LN);
}

void displayStudent(studentType student) {
    displayName(student.name);
    printf("%-8s %-5s%d", student.ID, student.course, student.yearLevel);
}

void displayArrayList(ArrayList arrylst) {
    for (int i = 0; i < arrylst.count; i++)
    {
        displayStudent(arrylst.stud[i]);
        printf("\n");
    }
    
}

#endif