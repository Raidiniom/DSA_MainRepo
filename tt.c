#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* String;

void main() {
    String myMessage = "Cyrene: Hello Wolrd";
    String emptyMessage = malloc(sizeof(char) * 64);

    strcpy(emptyMessage, "Proi Proi Proi Proi");

    printf("%-32s\n", myMessage); // Works
    printf("%-32s\n", emptyMessage); // Does not work
}