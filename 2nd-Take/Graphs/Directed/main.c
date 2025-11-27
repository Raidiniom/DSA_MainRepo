#include "graphd.h"

void main() {
    Graph grp = createGraph();

    createArc(&grp, 'A', 'B', 10);
    createArc(&grp, 'A', 'C', 5);

    displayGraph(grp);

    freeGraph(&grp);
}