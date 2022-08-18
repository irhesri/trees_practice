#include "../header.h"

// COMPARE FUNCTIONS FOR SEARCH

bool	compare_int(void *a, void *b)
{
	return (*(int *)a != *(int *)b);
}

bool	compare_str(void *a, void *b)
{
	char	*str1;
	char	*str2;

	str1 = a;
	str2 = b;
	if (!str1 && !str2)
		return (0);
	if (!str1 || !str2)
		return (1);
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return ((bool)(*str1 - *str2));
}