#include <stdio.h>
#include <stdlib.h>

typedef char String[10];

int main() {
    // struct Queue* priorityQueue = createEmptyPriorityQueue();
    
    String input;
    
    printf("Enter operations: \n");
    
    // do {
    //     scanf("%s ", input);
        
    //     if(strtok(input, " ") == '-') {
    //         printf("Do Dequeue\n");
    //     }
    //     else if (input[0] == '#') {
    //         printf("End\n");
    //         break;
    //     }
    //     else {
    //         printf("Do Enqueue\n");
    //     }
        
        
    // } while();
    
    
    char operation;
    int number, priority;
    
    do {
        scanf("%c", &operation);

        if (operation == '-')
        {
            printf("Dequeueu\n");
        }
        else if (operation == '+')
        {
            printf("Enqueueu\n");
        }
        

    } while(operation != '#');
    
    

    return 0;
}