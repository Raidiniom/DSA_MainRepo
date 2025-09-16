#include <stdio.h>

#include "adt.h"

void main() {
    ADTList *list;
    initADTList(&list);

    printf("%d", list->count);
}