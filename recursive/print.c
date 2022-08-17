#include "../header.h"

// PreOrder Traversal
void	preorder_print(t_node *root)
{
	if (!root)
		return ;
	printf("%d\t", *(int *)(root->content));
	preorder_print(root->left);
	preorder_print(root->right);
}

// InOrder Traversal
void	inorder_print(t_node *root)
{
	if (!root)
		return ;
	inorder_print(root->left);
	printf("%d\t", *(int *)(root->content));
	inorder_print(root->right);
}

// PostOrder Traversal
void	postorder_print(t_node *root)
{
	if (!root)
		return ;
	postorder_print(root->left);
	postorder_print(root->right);
	printf("%d\t", *(int *)(root->content));
}