#include "recur.h"

void main() {
    int arr[MAX];

    String test = "Hello World";

    for (int i = 0; i < MAX; i++)
    {
        arr[i] = i + 12;
    }
    
    recurArr(arr, MAX);

    reverseString(test);

    printf("Reversed String: %-100s", test);
}