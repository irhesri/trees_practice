#include "header.h"
int	g = 7;

t_node	*init1(int	**i)
{
	t_node	*root;

	for (int j = 0; j < g; j++)
		*(i + j) = malloc (sizeof(int));
	for (int j = 0; j < g; j++)
		**(i + j) = j + 1;

	root = NULL;
	for (int j = 0; j < g; j++)
		root = insert_node(root, *(i + j));
	return (root);
}

t_node	*init2(int	**i)
{
	int		j;
	t_node	*root;
	t_node	**n;

	n = malloc(sizeof(t_node *) * (g - 1));

	for (j = 0; j < g; j++)
		*(i + j) = malloc (sizeof(int));
	for (j = 0; j < g; j++)
		**(i + j) = j + 1;

	root = new_node(*i);
	for (j = 0; j < g - 1; j++)
		n[j] = new_node(*(i + j + 1));

	for (j = 0; j < g - 2; j++)
		(n[j])->right = n[j + 1];
	// root->right = n[0];
	root->right = n[0];
	free (n);
	return (root);
}

int	main(int ac, char **av)
{
	int		**k;
	int		**i;
	int		*tmp;
	t_node	*root;
	t_node	*node;

	/****************	INIT TREE *****************/
	if (ac != 1)
		g = atoi(av[1]);
	i = (int **)malloc (sizeof(int *) * (g));
	k = i;
	root = init1(i);
	// root = init2(i);
	/***********************************************/

	/*****************	TEST PROPERTIES	************/
	node = root;
	tmp = malloc(sizeof(int *));
	*tmp = g;
	if (ac > 2)
	{
		*tmp = atoi(av[2]);
		node = get_node(root, tmp, compare_int);
	}
	test_properties(root, node);
	/***********************************************/

	/*****************	TEST TYPES	****************/
	test_types(root);
	/***********************************************/

	/*****************	TEST PRINT	****************/
	test_print(root);
	/***********************************************/

	/*****************	TEST PRINT	****************/
	test_search(root, tmp, compare_int);
	/***********************************************/

	/********	TRASH	*********/
	free (tmp);
	free_tree(root);
	free (k);
}
