#include "library.h"

t_node	*new_node(void *content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->content = content;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int	max(int a, int b)
{
	return (a * (a >= b) + b * (a < b));
}

int	get_height(t_node *root)
{
	int	right;
	int	left;

	if (!root)
		return (-1);
	right = get_height(root->right);	
	left = get_height(root->left);
	return (max(right, left) + 1);
}