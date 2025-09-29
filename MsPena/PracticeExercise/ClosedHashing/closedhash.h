#ifndef CLOSEDHASH_H
#define CLOSEDHASH_H

#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 10

typedef enum {empty, deleted, occuppied} Status;

typedef struct {
    char letter;
    Status status;
} Entry;

typedef Entry Dictionary[MAXSIZE];

// Operations
void initDictionary(Dictionary dih) {
    for (int i = 0; i < MAXSIZE; i++)
    {
        dih[i].letter = '\0';
        dih[i].status = empty;
    }
}

int hashFunction(char letter) {
    return (letter - 65) % MAXSIZE;
}

void insert(Dictionary dih, char letter) {
    int hashValue = hashFunction(letter);

    if (dih[hashValue].status == empty || dih[hashValue].status == deleted)
    {
        dih[hashValue].letter = letter;
        dih[hashValue].status = occuppied;
    }
    else
    {
        for (int i = hashValue; i < MAXSIZE; i++)
        {
            if (dih[hashValue].status != occuppied)
            {
                dih[hashValue].letter = letter;
                dih[hashValue].status = occuppied;
            }
            
        }
        
    }
    
}

void delete(Dictionary dih, char letter) {
    int hashValue = hashFunction(letter);

    if (dih[hashValue].letter == letter)
    {
        dih[hashValue].letter = '\0';
        dih[hashValue].status = deleted;
    }
    else
    {
        for (int i = hashValue; i < MAXSIZE; i++)
        {
            if (dih[hashValue].status == letter)
            {
                dih[hashValue].letter = '\0';
                dih[hashValue].status = deleted;
            }
            
        }
        
    }
}

void display(Dictionary dih) {
    for (int i = 0; i < MAXSIZE; i++)
    {
        printf("[%d] | ", i);
        if (dih[i].status == deleted)
        {
            printf("deleted");
        }
        else if (dih[i].status == empty)
        {
            printf("empty");
        }
        else
        {
            printf("%c", dih[i].letter);
        }
        printf("\n");
    }
}

#endif