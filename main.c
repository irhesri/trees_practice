#include "header.h"
int	g = 7;

int	main(int ac, char **av)
{
	g = atoi(av[1]);
	int	**i;
	i = (int **)malloc (sizeof(int *) * (g));
	t_node *root;
	int	**k = i;
	for (int j = 0; j < g; j++)
		*(i + j) = malloc (sizeof(int));
	for (int j = 0; j < g; j++)
		**(i + j) = j + 1;

	root = NULL;
	for (int j = 0; j < g; j++)
		root = insert_node(root, *(i + j));
	// t_queue *q;
	t_node *new;

	// new =new_node(*(i + g));
	// (get_node(root, *(i + 5), compare_int)->left) = new;
	// q = new_queue(NULL);
	// int j = -1;
	// printf("%d\n", *(int *)((get_node(root, *(i + j - 1), compare_int))->content));
	// multiple_push(q, 4, get_node(root, *(i + --j), compare_int), get_node(root, *(i + --j), compare_int),get_node(root, *(i + --j), compare_int),get_node(root, *(i + --j), compare_int));
	// while (++j < 4)
	// {
	// 	push(q, get_node(root, *(i + j), compare_int));
	// }
	
	// t_node	**n;
	// n = malloc(sizeof(t_node *) * 4);
	// for (j=0; j<4; j++)
	// 	n[j] = get_node(root, *(i + j), compare_int);
	// j = -1;
	// multiple_push(q, 4, n[0], n[1], n[2], n[3]);
	// print_queue(q);

	// print_tree(root);
	// printf("%d\n", get_size(root));
	// printf("%d\n", get_height(root));
	
	// t_node *n;
	// int	*x = malloc(sizeof(int));
	// *(x) = 12;
	// n = get_parent(root, x, compare_int);
	// if (n)
	// 	printf("%d\n", *((int *)(n->content)));
	// free (x);
	// printf("%d\n", get_height(n));
	// printf("%d\n", get_size(n));
	// printf("%d\n", get_depth(root, n));
	printf("%d\n", is_complete(root));
	// print_tree(root);
	// print_tree_with_spaces(root);
	free_tree(root);


	free (k);
}
