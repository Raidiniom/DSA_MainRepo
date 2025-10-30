#include "header.h"

void main(void) {
    short int word[4] = {18255, 20292, 8266, 20290};
    int* arr = BitVectorToArray(word);
    char* message = decode(arr);

    displayPattern(arr);

    printf("[MESSAGE] %-60s\n", message);

    free(arr);
    free(message);
}