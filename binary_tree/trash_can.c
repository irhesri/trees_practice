#include "../header.h"

void	free_node(t_node *node)
{
	free(node->content);
	free (node);
}

void	free_tree(t_node *root)
{
	t_node		*tmp;
	t_queue		*q;
	t_q_node	*node;

	if (!root)
		return ;
	q = new_queue(root);
	while (q->size)
	{
		node = pop(q);
		if ((node->content)->right)
			push(q, (node->content)->right);
		if ((node->content)->left)
			push(q, (node->content)->left);
		free_node(node->content);
		free (node);
	}
	free_queue(q);
}