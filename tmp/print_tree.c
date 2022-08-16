#include "library.h"

void	print_tree(t_node *root)
{
	if (!root)
		return ;
	printf("%d\t", *(int *)(root->content));
	print_tree(root->left);
	print_tree(root->right);
}

void	print_tree_1(t_node *root)
{
	t_list		*queue;
	t_lst_node	*node;

	queue = new_list();
	push_back(queue, root);
	push_back(queue, NULL);
	node = pop_front(queue);
	while (node)
	{
		if (node->content)
		{
			printf("%d\t", *(int *)((t_node *)(node->content))->content);
			if (((t_node *)(node->content))->left)
				push_back(queue, ((t_node *)(node->content))->left);
			if (((t_node *)(node->content))->right)
				push_back(queue, ((t_node *)(node->content))->right);
		}
		else
		{
			printf("\n");
			if (queue->head)
				push_back(queue, NULL);
		}
		node = pop_front(queue);
	}
}

void	print_tree_2(t_node *root)
{
	int			i;
	int			n;
	// int			x;
	t_list		*queue;
	t_lst_node	*node;

	queue = new_list();
	push_back(queue, root);
	n = 1;
	// x = pow(2, get_height(root)/* + 1*/);
	while (n <= pow(2, get_height(root)))
	{
		// print_tabs(x);
		i = -1;
		while (++i < n)
		{
			node = pop_front(queue);
			if(node && node->content)
			{
				printf("%d\t", *(int *)((t_node *)(node->content))->content);
				push_back(queue, ((t_node *)(node->content))->left);
				push_back(queue, ((t_node *)(node->content))->right);
			}
			else
			{
				printf("-\t");
				push_back(queue, NULL);
				push_back(queue, NULL);
			}
			// print_tabs((x * 2) * (i < (n - 1)));
		}
		printf("\n\n");
		// x /= 2;
		n *= 2;
	}
}