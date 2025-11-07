#ifndef RECUR_H
#define RECUR_H

#include <stdio.h>
#include <string.h>

#define MAX 10

typedef char String[56];

void recurArr(int arr[], int max) {
    if (max <= 0) return;
    printf("%d ", arr[0]);
    recurArr(arr + 1, max - 1);
}

void reverseHelper(String str, int start, int end) {
    if (start >= end) return;
    
    char hold = str[start];
    str[start] = str[end];
    str[end] = hold;

    reverseHelper(str, start + 1, end - 1);
}

void reverseString(String str) {
    int length = strlen(str) - 1;

    reverseHelper(str, 0, length);
}

#endif