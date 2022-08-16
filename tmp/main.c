#include "library.h"

// t_node	*init()
// {
// 	int *t = malloc(sizeof(int) * 20);
// 	int	i = -1;
// 	t_node	*root;
// 	t_node	**n = malloc(sizeof(t_node *) * 100);
	
// 	while (++i < 10)
// 	{
// 		t[i] = i + 1;
// 		*(n + i) = new_node(t + i);
// 	}
// 	t[i] = 0;
// 	root = new_node(t + i);
// 	root->left = *n;
// 	root->right = *(n + 1);

// 	(*n)->left = *(n + 2);
// 	(*n)->right = *(n + 3);

// 	(*(n + 1))->left = *(n + 4);
// 	(*(n + 1))->right = *(n + 5);

// 	(*(n + 5))->right = *(n + 6);
// 	return (root);
// }
void	insert_node(t_node **root, void *content);

t_node	*init()
{
	int *t = malloc(sizeof(int) * 20);
	int	i = -1;
	t_node	*root;
	t_node	**n = malloc(sizeof(t_node *) * 100);
	
	while (++i < 10)
	{
		t[i] = i;

	}
	root = new_node(t);
	i = 0;
	while (++i < 10)
		insert_node(&root, t + i);
	return (root);
}

void	insert_node(t_node **root, void *content)
{
	t_node		*new;
	t_list		*queue;
	t_lst_node	*node;

	new = new_node(content);
	if (!*root)
	{
		(*root) = new;
		return ;
	}
	queue = new_list();
	push_back(queue, root);
	while (queue->size > 0)
	{
		node = pop_front(queue);
		if (node && !(((t_node *)(node->content))->left))
		{
			((t_node *)(node->content))->left = new;
			return ;
		}
		if (node && !(((t_node *)(node->content))->right))
		{
			((t_node *)(node->content))->right = new;
			return ;
		}
		push_back(queue, ((t_node *)(node->content))->left);
		push_back(queue, ((t_node *)(node->content))->right);
	}
}

int	main()
{
	t_list	*lst;
	t_node	*root;

	root = init();
	print_tree_1(root);
	// try (root);
	// printf ("%zu\n", get_height(root));
	// lst = new_list();
	// int	*i = malloc(sizeof(int));
	// i[0] = 0;
	// push_back(lst, i);
	// push_back(lst, i);
	// push_back(lst, i);
	// push_back(lst, i);
	// print_list(lst);
	// while (lst->head)
	// {
	// 	printf("-");
	// 	pop_front(lst);
	// }
	
	// pop_front(lst);
	return 0;
}