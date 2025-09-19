#include "arrstack.h"

int main(void) {
    Can pringles[3] = {{.top = -1}, {.top = -1}, {.top = -1}};
    
    bool stopProgram = true;

    while (stopProgram)
    {
        int choice;

        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 0:
                pushContainer(pringles, createChip(flavorChoice(), weightChoice()));
                break;

            case 1:
                popContainer(pringles);
                break;

            case 2:
                displayAllCans(pringles);
                break;

            case 3:
                printf("Stopping Program!\n");
                stopProgram = false;
                break;
            
            default:
                printf("Not one of the option!\n");
                break;
        }
    }
    
    return 0;
}