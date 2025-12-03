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

void insertData(ADTlist* adt, Persontype person) {
    if (adt->count < MAX)
    {
        adt->list[adt->count++] = person;
    }
    
}

void displayADTList(ADTlist adt) {
    for (int i = 0; i < adt.count; i++)
    {
        displayPerson(adt.list[i]);
    }
    
}

#endif