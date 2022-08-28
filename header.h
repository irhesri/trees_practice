#ifndef HEADER_H
# define HEADER_H

# include "./queue/queue.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <math.h>

// OTHER FUNCTIONS
int		max(int a, int b);
char	error(char *str);

// COMPARE FUNCTIONS FOR TREE SEARCH
int		compare_int(void *a, void *b);
int		compare_str(void *a, void *b);

// PRINTING FUNCTIONS
void	print_int(void *content, const char *str);
void	print_char(void *content, const char *str);
void	print_str(void *content, const char *str);
void	print_address(void *content, const char *str);


// TESTS
void	test_properties(t_node *root, t_node *node);
void	test_types(t_node *root);
void	test_search(t_node *root, void *content, int (*compare)(void *, void *));
void	test_print(t_node *root);
void	test_rotation(t_node *root, void *content, int (*compare)(void *, void *));

#endif