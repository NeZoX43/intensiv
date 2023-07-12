CC = gcc
FLAGS = -Wall -Werror -Wextra 

doors:
		$(CC) $(FLAGS) dmanager_module.c -o hello

build_door: dmanager_module.c
		$(CC) $(FLAGS) -DBUILD=1 dmanager_module.c -o ../build/Quest_1 

build_2: list.c list_test.c 
		$(CC) $(FLAGS) list.c list_test.c -o ../build/Quest_2

build_3:
		$(CC) $(FLAGS) stack.c stack_test.c -o ../build/Quest_3

clean: 
		rm  -rf *.o hello ../build/Quest_1 ../build/Quest_2 ../build/Quest_3