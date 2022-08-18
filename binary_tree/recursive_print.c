#include "../header.h"

// PreOrder Traversal
void	preorder_print(t_node *root, void (*print)(void *, const char *))
{
	if (!root)
		return ;
	print((root->content), "\t");
	preorder_print(root->left, print);
	preorder_print(root->right, print);
}

// InOrder Traversal
void	inorder_print(t_node *root, void (*print)(void *, const char *))
{
	if (!root)
		return ;
	inorder_print(root->left, print);
	print((root->content), "\t");
	inorder_print(root->right, print);
}

// PostOrder Traversal
void	postorder_print(t_node *root, void (*print)(void *, const char *))
{
	if (!root)
		return ;
	postorder_print(root->left, print);
	postorder_print(root->right, print);
	print((root->content), "\t");
}