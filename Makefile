all:
	gcc *.c ./recursive/*.c -lm
#./non-recursive/*.c -g 

san:
	gcc *.c ./recursive/*.c -lm -g -fsanitize=address
#./non-recursive/*.c

val:
	valgrind ./a.out