#include "../header.h"

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

int	get_depth(t_node *root, t_node *n)
{
	bool		b;
	int			depth;
	t_node		*tmp;
	t_queue		*q;
	t_q_node	*node;

	b = 0;
	depth = 0;
	q = new_queue(root);
	push(q, NULL);
	while (!b && q->size)
	{
		node = pop(q);
		if (!node->content && ++depth)
			push(q, NULL);
		else
		{
			tmp = (node->content)->right;
			b = (node->content == n);
			for (int j = 0; !b && j < 2; j++)
			{
				if (tmp)
				{
					if (!b && tmp)
						push(q, tmp);
				}
				tmp = (node->content)->left;
			}
		}
		free(node);
	}
	free_queue(q);
	if (!b)
		return (-1);
	return (depth);
}
