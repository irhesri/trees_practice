# include "header.h"

// GET PROPERTIES OF NODE
void	test_properties(t_node *root, t_node *node)
{
	printf("\nHEIGHT:\t%d\n", get_height(node));
	printf("SIZE:  \t%d\n", get_size(node));
	printf("DEPTH: \t%d\n", get_depth(root, node));
}

void	types(t_node *root, int n)
{
	static bool	(*ptr[8])(t_node *);
	static const char *str[8] = {"full", "complete", "perfect", "balanced", "pathological", "left skewed", "right skewed", "skewed"};

	if (!ptr[0])
	{
		ptr[0] = is_full;
		ptr[1] = is_complete;
		ptr[2] = is_perfect;
		ptr[3] = is_balanced;
		ptr[4] = is_pathological;
		ptr[5] = is_left_skewed;
		ptr[6] = is_right_skewed;
		ptr[7] = is_skewed;
	}
	if (!(ptr[n])(root))
		printf("not ");
	printf("%s\n", str[n]);
}

void	test_types(t_node *root)
{
	int	i;

	i = -1;
	printf("\nTHIS TREE IS:\n");
	while (++i < 8)
	{
		printf("\t--->");
		types(root, i);
	}
}

void	test_search(t_node *root, void *content, int (*compare)(void *, void *))
{
	t_node	*node;

	node = get_node(root, content, compare);
	printf("\nNODE CONTENT:\t%d", *(int *)(node->content));
	node = get_parent(root, content, compare);
	printf("\nPARENT NODE CONTENT:\t%d\n", *(int *)(node->content));
}

void	test_print(t_node *root)
{
	printf("\nPREORDER PRINT:\t\t");
	preorder_print(root, print_int);
	printf("\nINORDER PRINT:\t\t");
	inorder_print(root, print_int);
	printf("\nPOSTORDER PRINT:\t");
	postorder_print(root, print_int);
	printf("\n");
	printf("\nPRINT NODES:\n");
	print_tree(root, print_int);
	// printf("\nPRINT TREE:\n");
	// print_tree_with_spaces(root, print_int);
	printf("\n");
}