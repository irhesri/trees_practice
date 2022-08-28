#include "../header.h"

typedef struct s_avl
{
	void	*content;
	short	balance_factor;
} t_avl;

t_node	*left_rotation(t_node *root, t_node *node)
{
	t_node	*right;
	t_node	*parent;

	if (!root || !node || !node->right)
		return (root);
	parent = binary_search_parent(root, node->content, compare_int);
	right = node->right;
	node->right = right->left;
	right->left = node;
	if (!parent)
		return (right);
	if (parent->right == node)
		parent->right = right;
	else
		parent->left = right;
	return (root);
}

t_node	*right_rotation(t_node *root, t_node *node)
{
	t_node	*left;
	t_node	*parent;

	if (!root || !node || !node->left)
		return (root);
	parent = binary_search_parent(root, node->content, compare_int);
	left = node->left;
	node->left = left->right;
	left->right = node;
	if (!parent)
		return (left);
	if (parent->right == node)
		parent->right = left;
	else
		parent->left = left;
	return (root);
}

// t_node	*avl_insertion(t_node *root, void *content)
// {
// 	t_avl	*avl;
// 	t_node	*new;
// 	t_queue	*q;

// 	avl = malloc(sizeof(t_avl));
// 	avl->content = content;
// 	avl->balance_factor = 0;
// 	new = new_node(avl);
// 	if (!root)
// 		return (new);
// 	while (1)
// 	{
		
// 	}
	
// }