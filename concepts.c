#include <stdio.h>

int arr[5];
char chararry[5];

void main() {
    for (int i = 0; i < 5; i++)
    {
        printf("%d | int: %d, char: %c\n", i, arr[i], (chararry[i] == '\0') ? 'T' : 'F');
    }
    
}