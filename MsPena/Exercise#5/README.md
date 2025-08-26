## Version 1

```c
LIST myList;
initialize(&myList);

insert(&myList, create_student(create_name("Ratilla", "Voltaire", 'L'), "07402931", "BSIT-2"));
insert(&myList, create_student(create_name("Santos", "Angela", 'D'), "59012348", "BSIT-2"));
insert(&myList, create_student(create_name("Gerozaga", "John", 'S'), "98123477", "BSIT-2"));
insert(&myList, create_student(create_name("Dianco", "Clarence", 'N'), "74829103", "BSIT-2"));
insert(&myList, create_student(create_name("Kabanlit", "Ivan", 'R'), "10394857", "BSIT-2"));
insert(&myList, create_student(create_name("Magdalen", "Mary", 'P'), "82736491", "BSIT-2"));

printList(myList);

printf("location at index %d\n", locate(myList, "74829103"));
print_student(retrieve(myList, "07402931"));

printf("\n\n");
delete(&myList, "07402931");
printList(myList);
printf("\n\n");
delete(&myList, "98123477");
printList(myList);
printf("\n\n");
delete(&myList, "82736491");
printList(myList);
```

---