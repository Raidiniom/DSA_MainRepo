#include "queue.h"

void main() {
    Queue thisQ = initQ();

    enqueueSorted(&thisQ, 1);
    enqueueSorted(&thisQ, 7);
    enqueueSorted(&thisQ, 4);
    enqueueSorted(&thisQ, 2);

    displayQueue(&thisQ);
}