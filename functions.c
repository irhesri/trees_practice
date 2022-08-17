#include "header.h"

char	error(char *str)
{
	fprintf(stderr, "%s\n", str);
	exit (1);
}

int		max(int a, int b)
{
	return (a * (a >= b) + b *(a < b));
}

short	compare_int(void *a, void *b)
{
	return (*(int *)a != *(int *)b);
}