#ifndef CLOSEDIH_H
#define CLOSEDIH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXSIZE 10

typedef enum {empty, occupied, deleted} Status;

typedef struct {
    char FName[24];
    char LName[16];
    char MI;
} Person;

typedef struct {
    Person person;
    Status status;
} Entry;

typedef Entry Dictionary[MAXSIZE];

// Helper Functions
Person createPerson(char* FName, char* LName, char MI) {
    Person initPerson;

    strcpy(initPerson.FName, FName);
    strcpy(initPerson.LName, LName);
    initPerson.MI = MI;

    return initPerson;
}

void printPerson(Person psn) {
    printf("%-10s %c, %-10s", psn.FName, psn.MI, psn.LName);
}

int nameHash(char* FName, char* LName) {
    int sum = 0;

    // Add up characters from first name
    for (int i = 0; FName[i] != '\0'; i++) {
        sum += FName[i];
    }

    // Add up characters from last name
    for (int i = 0; LName[i] != '\0'; i++) {
        sum += LName[i];
    }

    // Fit into dictionary size
    return sum % MAXSIZE;
}



// Operations
void initDictionary(Dictionary dih) {
    for (int i = 0; i < MAXSIZE; i++)
    {
        dih[i].status = empty;
    }
}

int search(Dictionary dih, char* FName, char* LName) {
    int index = nameHash(FName, LName);  // removed MI
    int start = index;

    do {
        if (dih[index].status == occupied &&
            strcmp(dih[index].person.FName, FName) == 0 &&
            strcmp(dih[index].person.LName, LName) == 0) {
            return index;
        }

        index = (index + 1) % MAXSIZE;
    } while (index != start);

    return -1;
}


bool insert(Dictionary dih, Person psn) {
    int index = nameHash(psn.FName, psn.LName);  // removed MI
    int start = index;

    do {
        if (dih[index].status == empty || dih[index].status == deleted) {
            dih[index].person = psn;
            dih[index].status = occupied;
            return true;
        }
        index = (index + 1) % MAXSIZE;
    } while (index != start);

    return false;
}

bool delete(Dictionary dih, char* FName, char* LName) {
    int index = nameHash(FName, LName), start = index;

    do
    {
        if (dih[index].status == occupied && strcmp(dih[index].person.FName, FName) == 0 && strcmp(dih[index].person.LName, LName) == 0) {
            dih[index].status = deleted;
            return true;
        }

        index = (index + 1) % MAXSIZE;
    } while (index != start);
    

    return false;
}

void display(Dictionary dih, char* label) {
    printf("%-20s\n", label);
    for (int i = 0; i < MAXSIZE; i++)
    {
        printf("[%d] | ", i);
        if (dih[i].status == empty)
        {
            printf("empty");
        }
        else if (dih[i].status == deleted)
        {
            printf("deleted");
        }
        else
        {
            printPerson(dih[i].person);
        }
        printf("\n");
    }
    
}

#endif