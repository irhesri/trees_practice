#include "header.h"

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

int	get_size(t_node *root)
{
	int			size;
	t_queue		*q;
	t_q_node	*node;
	
	if (!root)
		return (0);
	size = 0;
	q = new_queue(root);
	while (q->size)
	{
		node = pop(q);
		size++;
		if ((node->content)->right)
			push(q, (node->content)->right);
		if ((node->content)->left)
			push(q, (node->content)->left);
		free (node);
	}
	free_queue(q);
	return (size);
}

// ALL LEVELS ARE FULL
short	is_perfect(t_node *root)
{
	int	size;
	int	height;

	size = get_size(root);
	height = get_height(root);
	return (size == (pow(2, height + 1) - 1));
}

// EVERY NODE HAS 0 OR 2 CHILDS
short	is_full(t_node *root)
{
	short		b;
	t_queue		*q;
	t_q_node	*node;

	if (!root)
		return (1);
	q = new_queue(root);
	while (q->size)
	{
		node = pop(q);
		b = !(node->content)->right + !(node->content)->left;
		if (!b)
		{
			push(q, (node->content)->right);
			push(q, (node->content)->left);
		}
		free (node);
		if (b == 1)
			break;
	}
	free_queue(q);
	if (b == 1)
		return (0);
	return(1);
}

int	get_depth(t_node *root, t_node *node)
{
	return(get_height(root) - get_height(node));
}
