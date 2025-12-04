#include "grap.h"

void main() {
    directedAdjList myList;
    initDirectedAdjList(&myList);

    // A
    addEdge(&myList, 'A', createAdjType('F', 3));
    addEdge(&myList, 'A', createAdjType('E', 6));

    // B
    addEdge(&myList, 'B', createAdjType('F', 10));
    addEdge(&myList, 'B', createAdjType('E', 6));
    addEdge(&myList, 'B', createAdjType('C', 3));
    addEdge(&myList, 'B', createAdjType('A', 4));

    // C
    addEdge(&myList, 'C', createAdjType('D', 6));
    addEdge(&myList, 'C', createAdjType('A', 4));

    // D
    addEdge(&myList, 'D', createAdjType('E', 3));
    addEdge(&myList, 'D', createAdjType('B', 6));
    addEdge(&myList, 'D', createAdjType('A', 8));

    // E
    addEdge(&myList, 'E', createAdjType('F', 6));
    addEdge(&myList, 'E', createAdjType('C', 6));

    // F
    addEdge(&myList, 'F', createAdjType('D', 3));
    addEdge(&myList, 'F', createAdjType('B', 3));


    displayAdjList(myList);
}