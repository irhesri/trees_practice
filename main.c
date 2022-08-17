#include "header.h"
int	g = 7;

int	main(int ac, char **av)
{
	g = atoi(av[1]);
	int	**i;
	i = (int **)malloc (sizeof(int *) * g);
	t_node *root;
	int	**k = i;
	for (int j = 0; j < g; j++)
		*(i + j) = malloc (sizeof(int));
	for (int j = 0; j < g; j++)
		**(i + j) = j + 1;

	root = NULL;
	for (int j = 0; j < g; j++)
		root = insert_node(root, *(i + j));
	// print_tree(root);
	// printf("%d\n", get_size(root));
	// printf("%d\n", get_height(root));
	
	t_node *n;
	int	*x = malloc(sizeof(int));
	*(x) = 12;
	n = get_parent(root, x, compare_int);
	if (n)
		printf("%d\n", *((int *)(n->content)));
	free (x);
	// printf("%d\n", get_height(n));
	// printf("%d\n", get_size(n));
	// printf("%d\n", get_depth(root, n));

	free_tree(root);


	free (k);
}


// int	main()
// {
// 	int	*i = malloc (sizeof(int) * 4);
// 	t_queue *q;

// 	q = new_queue();

// 	for (int j = 0; j < 4; j++)
// 		i[j] = j;
// 	for (int j = 0; j < 4; j++)
// 		push(q, (t_node *)(i + j));
// 	print_queue(q);
// 	free(i);
// 	free_queue(q);
// }