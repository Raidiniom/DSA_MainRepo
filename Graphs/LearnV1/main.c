#include <stdio.h>
#include <stdlib.h>
#include "graphlearn.h"

int main() {

    Graph my_graph;

    initialize_graph(&my_graph);

    display_graph(my_graph);

    return 0;
}
