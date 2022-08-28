
NAME = t
MAIN = main.c
TEST = tests.c
QUEUE = ./queue/*.c
TREE = ./binary_tree/*.c
FUNCTIONS = ./additional_functions/*.c
CFLAGS = -lm -g -fsanitize=address
CC = gcc

all:
	$(CC) $(MAIN) $(QUEUE) $(TREE) $(TEST) $(FUNCTIONS) $(CFLAGS)
