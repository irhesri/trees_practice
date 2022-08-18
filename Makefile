all:
	gcc *.c ./queue/*.c ./tree/*.c ./additional_functions/*.c -lm
#./non-recursive/*.c -g 

san:
	gcc *.c ./queue/*.c ./tree/*.c ./additional_functions/*.c -lm -g -fsanitize=address
#./non-recursive/*.c

val:
	valgrind ./a.out