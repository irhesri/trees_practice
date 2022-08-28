#include "../header.h"

t_node	*new_node(void *content)
{
	t_node	*new;

	new = (t_node *) malloc(sizeof(t_node));
	if (!new)
		error("allocation error");
	new->content = content;
	new->right = NULL;
	new->left = NULL;
	return (new);
}

// Making A Complete Binary Tree
t_node	*insert_node(t_node *root, void *content)
{
	char		b;
	t_node		*new;
	t_queue		*q;
	t_q_node	*node;

	new = new_node(content);
	if (!root)
		return (new);
	b = 0;
	q = new_queue(root);
	while (!b/* && q->size*/)
	{
		node = pop(q);
		if (!((node->content)->left) && ++b)
			(node->content)->left = new;
		else if (!((node->content)->right) && ++b)
			(node->content)->right = new;
		else
			multiple_push(q, 2, (node->content)->left, (node->content)->right);
		free (node);
	}
	free_queue(q);
	return (root);
}

// RIGHT NODE CONTENT BIGGER THAN THE PARENT CONTENT
// LEFT NODE CONTENT SMALLER THAN THE PARENT CONTENT
t_node	*bst_insertion(t_node *root, void *content)
{
	int		b;
	t_node	*new;
	t_node	*node;

	new = new_node(content);
	if (!root)
		return (new);
	node = root;
	while (node)
	{
		b = compare_int(content, node->content);
		if (!b)
			break;
		if (b > 0)
		{
			if (!node->right)
			{
				node->right = new;
				break;
			}
			node = node->right;
		}
		else
		{
			if (!node->left)
			{
				node->left = new;
				break;
			}
			node = node->left;
		}
	}
	return (root);
}