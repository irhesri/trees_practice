#include "../header.h"

// FUNCTIONS FOR TREE PRINTING

void	print_int(void *content, const char *str)
{
	printf("%d", *(int *)content);
	if (str)
		printf("%s", str);
}

void	print_char(void *content, const char *str)
{
	printf("%d", *(char *)content);
	if (str)
		printf("%s", str);
}

void	print_str(void *content, const char *str)
{
	printf("%s", (char *)content);
	if (str)
		printf("%s", str);
}

void	print_address(void *content, const char *str)
{
	printf("%p", content);
	if (str)
		printf("%s", str);
}