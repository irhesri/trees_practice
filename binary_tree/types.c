#include "../header.h"


// EVERY NODE HAS 0 OR 2 CHILDS
bool	is_full(t_node *root)
{
	short		b;
	t_queue		*q;
	t_q_node	*node;

	if (!root)
		return (1);
	b = 0;
	q = new_queue(root);
	while (b != 1 && q->size)
	{
		node = pop(q);
		b = !(node->content)->right + !(node->content)->left;
		if (!b)
			multiple_push(q, 2, (node->content)->left, (node->content)->right);
		free (node);
	}
	free_queue(q);
	return(b != 1);
}

// ALL LEVELS ARE FULL
bool	is_perfect(t_node *root)
{
	int	size;
	int	height;

	size = get_size(root);
	height = get_height(root);
	return (size == (pow(2, height + 1) - 1));
}


// 	IS COMPLETE
static bool	check_inside_nodes(t_node *root, t_queue *q, int *size)
{
	int			x;
	int			height;
	bool		b = 0;
	t_q_node	*node;

	x = 0;
	height = get_height(root);
	while (!b && height > 1)
	{
		node = pop(q);
		if (!node->content)
		{
			if (x != *size)
				b = 1;
			height--;
			x = 0;
			(*size) *= 2;
			push(q, NULL);
		}
		else
		{
			x++;
			if ((node->content)->left)
				push(q, (node->content)->left);
			else
				b = 1;
			if ((node->content)->right)
				push(q, (node->content)->right);
			else
				b = 1;
		}
		free (node);
	}
	return (b);
}

// 	IS COMPLETE
static bool check_lowest_levels(t_node *root, t_queue *q, int size)
{
	int			x;
	bool		b = 0;
	bool		n = 1;
	t_q_node	*node;

	x = 0;
	while (!b && q->size)
	{
		node  = pop(q);
		if (!(node->content) && size != x)
			b = 1;
		else if (node->content)
		{
			x++;
			if (n)
			{
				if (!(node->content)->left)
					n = 0;
				if (!n && (node->content)->right)
					b = 1;
				else if (!(node->content)->right)
					n = 0;
			}
			else if (!n && ((node->content)->left || (node->content)->right))
				b = 1;
		}
		free (node);
	}
	return (b);
}

bool	is_complete(t_node *root)
{
	int			size;
	bool		b;
	t_queue		*q;
	t_q_node	*node;

	if (!root)
		return (1);
	b = 0;
	size = 1;
	q = new_queue(root);
	push(q, NULL);
	b = check_inside_nodes(root, q, &size);
	if (!b)
		b = check_lowest_levels(root, q, size);
	free_queue(q);
	return (!b);
}

//************************************************	test it !!!
bool	is_balanced(t_node *root)
{
	bool		b;
	t_queue		*q;
	t_q_node	*node;

	if (!root)
		return (1);
	b = 0;
	q = new_queue(root);
	while (!b && q->size)
	{
		node = pop(q);
		if (abs(get_height((node->content)->right) - get_height((node->content)->left)) > 1)
			b = 1;
		if ((node->content)->right)
			push(q, (node->content)->right);
		if ((node->content)->left)
			push(q, (node->content)->left);
		free (node);
	}
	free_queue(q);
	return (!b);
}

bool	is_pathological(t_node *root)
{
	short		b;
	t_queue		*q;
	t_q_node	*node;

	if (!root)
		return (1);
	q = new_queue(root);
	while (b != 2 && q->size)
	{
		b = 0;
		node = pop(q);
		if ((node->content)->right && ++b)
			push(q, (node->content)->right);
		if ((node->content)->left && ++b < 2)
			push(q, (node->content)->left);
		free (node);
	}
	free_queue(q);
	return (b != 2);
}

bool	is_left_skewed(t_node *root)
{
	bool		b;
	t_queue		*q;
	t_q_node	*node;

	if (!root)
		return (1);
	b = 0;
	q = new_queue(root);
	while (!b && q->size)
	{
		node = pop(q);
		if ((node->content)->right)
			b = 1;
		if (!b && (node->content)->left)
			push(q, (node->content)->left);
		free (node);
	}
	free_queue(q);
	return (!b);	
}

bool	is_right_skewed(t_node *root)
{
	bool		b;
	t_queue		*q;
	t_q_node	*node;

	if (!root)
		return (1);
	b = 0;
	q = new_queue(root);
	while (!b && q->size)
	{
		node = pop(q);
		if ((node->content)->left)
			b = 1;
		if (!b && (node->content)->right)
			push(q, (node->content)->right);
		free (node);
	}
	free_queue(q);
	return (!b);	
}

bool	is_skewed(t_node *root)
{
	return (is_left_skewed(root) || is_right_skewed(root));
}