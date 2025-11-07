#ifndef RECUR_H
#define RECUR_H

#include <stdio.h>

void addUntil(int start, int end) {
    if (start <= end)
    {
        printf("%d ", start);
        addUntil(start + 1, end);
    }
}

int sumOf(int number) {
    if (number != 0) return number += sumOf(number - 1);
}

void fizzbuzz(int start, int end) {
    if (start <= end)
    {
        if (start % 15 == 0)
        {
            printf("%d : FizzBuzz\n", start);
        }
        else if (start % 5 == 0)
        {
            printf("%d : Buzz\n", start);
        }
        else if (start % 3 == 0)
        {
            printf("%d : Fizz\n", start);
        }
        else
        {
            printf("%d : \n", start);
        }
        
        fizzbuzz(start + 1, end);
    }
    
}

#endif