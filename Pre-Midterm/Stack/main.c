#include "arrstack.h"

void main() {
    Can pringles[3] = {{.top = -1}, {.top = -1}, {.top = -1}};
    
    push(&pringles[0], createChip("Spicy", 2));
    push(&pringles[0], createChip("Spicy", 2));
    push(&pringles[0], createChip("Spicy", 2));
    push(&pringles[0], createChip("Mustard", 4));
    push(&pringles[0], createChip("Matcha", 3));

    displayAllCans(pringles);
}