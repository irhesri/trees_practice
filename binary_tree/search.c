#include "../header.h"

t_node	*get_node(t_node *root, void *content, int (*compare)(void *, void *))
{
	t_node		*tmp;
	t_queue		*q;
	t_q_node	*node;

	if (!root || !content)
		return (NULL);
	tmp = NULL;
	q = new_queue(root);
	while (!tmp && q->size)
	{
		node = pop(q);
		if (!compare(content, (node->content)->content))
			tmp = node->content;
		else
		{
			if ((node->content)->right)
				push(q, (node->content)->right);
			if ((node->content)->left)
				push(q, (node->content)->left);
		}
		free (node);
	}
	free_queue(q);
	return (tmp);
}

t_node	*get_parent(t_node *root, void *content, int (*compare)(void *, void *))
{
	t_node		*tmp;
	t_node		*res;
	t_queue		*q;
	t_q_node	*node;

	if (!root || !content || !compare(root->content, content))
		return (NULL);
	res = NULL;
	q = new_queue(root);
	while (!res && q->size)
	{
		node = pop(q);
		tmp = (node->content)->right;
		for (int i = 0; !res && i < 2; i++)
		{
			if (tmp && !compare(content, tmp->content))
				res = node->content;
			else if (tmp)
				push(q, tmp);
			tmp = (node->content)->left;
		}
		free (node);
	}
	free_queue(q);
	return (res);
}

t_node	*binary_search(t_node *root, void *content, int (*compare)(void *, void *))
{
	int		b;
	t_node	*node;

	if (!content)
		return (NULL);
	node = root;
	while (node)
	{
		b = compare(content, node->content);
		if (b == 0)
			return (node);
		if (b > 0)
			node = node->right;
		else
			node = node->left;
	}
	return (NULL);
}

t_node	*binary_search_parent(t_node *root, void *content, int (*compare)(void *, void *))
{
	int		b;
	t_node	*node;

	if (!root || !content || !compare(content, root->content))
		return (NULL);
	node = root;
	while (node)
	{
		b = compare(content, node->content);
		if (b > 0)
		{
			if (node->right && !compare(content, node->right->content))
				return (node);
			node = node->right;
		}
		else
		{
			if (node->left && !compare(content, node->left->content))
				return (node);
			node = node->left;
		}
	}
	return (NULL);
}