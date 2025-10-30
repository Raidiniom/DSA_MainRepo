#ifndef CLDIH_h
#define CLDIH_h

#include <stdio.h>
#include <stdlib.h>

#define max 20

typedef enum {
    EMPTY,
    DELETE,
    OCCUPIED,
} Status;

typedef struct {
    int element;
    Status status;
} Entry;

typedef Entry Dictionary[max];

int hashFunct(int element) {
    if (element < 0) element = -element;
    return element % max;
}

void initDictionary(Dictionary* dih) {
    for (int i = 0; i < max; i++)
    {
        (*dih)[i].element = 0;
        (*dih)[i].status = EMPTY;
    }
    
}

void insertElem(Dictionary* dih, int element) {
    int index = hashFunct(element);
    int start = index;

    do {
        if ((*dih)[index].status == EMPTY) {
            (*dih)[index].element = element;
            (*dih)[index].status = OCCUPIED;
            break;
        }
        // Go to next index (wrap around with % max)
        index = (index + 1) % max;
    } while (index != start);
}

void deleteElem(Dictionary* dih, int element) {
    int index = hashFunct(element);
    int start = index;

    do {
        if ((*dih)[index].status == OCCUPIED && (*dih)[index].element == element) {
            (*dih)[index].status = DELETE;
            printf("Deleted %d from index %d\n", element, index);
            return;
        }
        index = (index + 1) % max;
    } while (index != start);

    printf("%d not found in dictionary\n", element);
}

void display(Dictionary dih, char* label) {
    printf("-----%24s------\n", label);

    for (int i = 0; i < max; i++)
    {
        printf("%d | ", i);
        switch (dih[i].status)
        {
            case EMPTY: printf("[ EMPTY ]"); break;
            case DELETE: printf("[ DELETE ]"); break;
            default: printf("%d", dih[i].element); break;
        }
        printf("\n");
    }
    printf("\n");
}

#endif