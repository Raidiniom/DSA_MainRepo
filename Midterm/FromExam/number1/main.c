#include "header.h"

void main(void) {
    short int word[4]={17729,21074,18766,18259};
    int* arr = BitVectorToArray(word);
    char* message = decode(arr);

    displayPattern(arr);

    printf("[MESSAGE] %-60s\n", message);

    free(arr);
    free(message);
}