#include <stdio.h>
#include "adtlist.h"

void main() {
    List myList;
    init_list(&myList);

    insert_person(&myList, create_person("Voltaire", 23));
    insert_person(&myList, create_person("Charles", 20));
    insert_person(&myList, create_person("Ivan", 21));
    insert_person(&myList, create_person("Keith", 22));
    insert_person(&myList, create_person("Clarence", 19));
    insert_person(&myList, create_person("John", 24));
    
    display_list(myList);

    remove_person(&myList, "Ivan");

    display_list(myList);
}