#include <stdio.h>
#include <stdlib.h>

#include "AI_Help/GraphAH.h"

int main() {

    Graph learn_graph = create_graph(12);

    add_edge(&learn_graph, create_name("Voltaire", "Ratilla"), create_name("Clarence", "Diangco"));
    add_edge(&learn_graph, create_name("Clarence", "Diangco"), create_name("Charles", "Boqecosa"));
    add_edge(&learn_graph, create_name("Charles", "Boqecosa"), create_name("Voltaire", "Ratilla"));
    add_edge(&learn_graph, create_name("Yousif", "Ceballous"), create_name("Mark", "Gerozaga"));
    add_edge(&learn_graph, create_name("Ivan", "Jayme"), create_name("Clarence", "Diangco"));
    add_edge(&learn_graph, create_name("Mark", "Gerozaga"), create_name("Yousif", "Ceballous"));
    
    display_graph(learn_graph);

    return 0;
}
