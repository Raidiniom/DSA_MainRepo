#include <stdio.h>
#include <time.h>

#include "sortlink.h"

void main() {
    srand(time(NULL));
    
    Node initialList;
    initLinkList(&initialList);

    for (int i = 0; i < 20; i++)
    {
        insertNode(&initialList, rand() % 51);
    }
 
    printLinkList(initialList, "Initial List");

    bubbleSort(&initialList);
}