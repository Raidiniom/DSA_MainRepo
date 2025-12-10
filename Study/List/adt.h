#ifndef ADT_H
#define ADT_H

#include <stdio.h>
#include <string.h>

#define MAX 10

typedef char String[32];

typedef struct {
    String fname;
    String lname;
    int age;
} Persontype;

typedef struct {
    int count;
    Persontype list[MAX];
} ADTlist;

Persontype createPerson(char* fname, char* lname, int age) {
    Persontype initPerson;

    strcpy(initPerson.fname, fname);
    strcpy(initPerson.lname, lname);
    initPerson.age = age;

    return initPerson;
}

void displayPerson(Persontype person) {
    printf("%-16s, %-16s | %d\n", person.lname, person.fname, person.age);
}

void initADTList(ADTlist* adt) {
    adt->count = 0;
}

int findData(ADTlist adt, char* fname, char* lname) {
    for (int i = 0; i < adt.count; i++)
    {
        if (strcmp(adt.list[i].fname, fname) == 0 && strcmp(adt.list[i].lname, lname) == 0) return i;
        
    }
    
}

void insertData(ADTlist* adt, Persontype person) {
    if (adt->count < MAX)
    {
        adt->list[adt->count++] = person;
    }
    
}

void deleteData(ADTlist* adt, char* fname, char* lname) {
    int location = findData(*adt, fname, lname);

    for (int i = location; i < adt->count; i++)
    {
        adt->list[i] = adt->list[i + 1];
    }
    
    adt->count--;
}

void displayADTList(ADTlist adt, char* label) {
    printf("%-20s\n", label);
    for (int i = 0; i < adt.count; i++)
    {
        displayPerson(adt.list[i]);
    }
    
}

#endif