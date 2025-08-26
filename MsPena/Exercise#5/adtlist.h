#ifndef ADTLIST_H
#define ADTLIST_H

/**
 * This header file is about ADT list - Array Implementation
 * 
 * Functions to implement
 * insert 
 * delete
 * locate
 * retrieve
 * makeNull
 * printList
 * 
 * Programmer: Voltaire Ratilla
 * create at: 26/8/2025
 * done at: ~/~/~
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

void makeNull(LIST* list) {
    list->count = 0;
}

void insert(LIST* list, Student student) {
    list->student[list->count++] = student;
}

int locate(LIST list, char* ID) {
    for (int i = 0; i < list.count; i++)
    {
        if (strcmp(list.student[i].ID, ID) == 0)
        {
            return i;
        }
        
    }
    return -1;
}

void print_name(Name name) {
    printf("%s %c, %s%5s", name.FName, name.MI, name.LName, " ");
}

void print_student(Student student) {
    print_name(student.name);
    printf("- ID: %s Course: %s\n", student.ID, student.course);
}

void printList(LIST list) {
    for (int i = 0; i < list.count; i++)
    {
        print_student(list.student[i]);
    }
    
}

#endif