#include "../header.h"

void	print_tree(t_node *root, void (*print)(void *, const char *))
{
	t_queue		*q;
	t_q_node	*node;

	if (!root)
		return ;
	q = new_queue(NULL);
	multiple_push(q, 2, root, NULL);
	while (q->size)
	{
		node = pop(q);
		if (node->content)
		{
			print((node->content)->content, "\t");
			if ((node->content)->left)
				push(q, (node->content)->left);
			if ((node->content)->right)
				push(q, (node->content)->right);
		}
		else
		{
			printf("\n");
			if (q->head)
				push(q, NULL);
		}
		free (node);
	}
	free_queue(q);
}
// check it again
void	print_spaces(int x)
{
	while (x && --x)
		printf(" ");
}

void	print_tree_with_spaces(t_node *root, void (*print)(void *, const char *))
{
	int			i;
	int			n;
	int			x;
	t_queue		*q;
	t_q_node	*node;

	n = 1;
	if (!root)
		return ;
	q = new_queue(root);
	x = pow(2, get_height(root) + 1);
	while (n <= (pow(2, get_height(root) + 1)))
	{
		i = -1;
		print_spaces(x);
		while (++i < n && q->size)
		{
			node = pop(q);
			if(node && node->content)
			{
				print((node->content)->content, NULL);
				multiple_push(q, 2, (node->content)->left, (node->content)->right);
			}
			else
				printf("-");
			print_spaces((x * 2) * (i < (n - 1)));
			free (node);
		}
		printf("\n\n");
		x /= 2;
		n *= 2;
	}
	free_queue(q);
}
