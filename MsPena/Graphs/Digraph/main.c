#include "graphd.h"

void main() {
    Graph grp = createGraph();

    insertNode(&grp, 'A', 'B', 5);

    displayGraph(grp);
}