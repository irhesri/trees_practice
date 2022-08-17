#include "header.h"

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
		{
			push(q, (node->content)->left);
			push(q, (node->content)->right);
		}
		free (node);
	}
	free_queue(q);
	return (root);
}


// assuming that content is int in the next funtions

// short	compare(t_node *node, int *content)
// {
// 	return (*(int *)(node->content) != *content);
// }

// t_node	*get_parent_node(t_node *root, void *content)
// {
// 	t_queue		*q;
// 	t_q_node	*node;

// 	if (!root /*|| (root && *(int *)(root->content) == *(int *)content)*/)
// 		return (NULL);
// 	q = new_queue(root);
// 	while (q->size)
// 	{
// 		node = pop(q);
// 		if (!compare((node->content)->right, content))
// 			return (node);
// 		if (!compare((node->content)->left, content))
// 			return (node);
		
// 	}
	
// }

// t_node	*delete_node(t_node *root, void *content)
// {

// }