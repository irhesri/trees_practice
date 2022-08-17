#ifndef TREE_H
# define TREE_H

typedef struct s_node
{
	void			*content;
	struct s_node	*right;
	struct s_node	*left;
} t_node;

// TREE OPERATIONS
t_node	*insert_node(t_node *root, void *content);

// TREE PROPERTIES
int		get_height(t_node *root);
int		get_size(t_node *root);
int		get_depth(t_node *root, t_node *node);
// int		get_depth(t_node *root, void *content)
short	is_perfect(t_node *root);
short	is_full(t_node *root);

// TREE FUNTIONS
t_node	*get_node(t_node *root, void *content, short (*compare)(void *, void *));
t_node	*get_parent(t_node *root, void *content, short (*compare)(void *, void *));
// TRASH CAN
void	free_tree(t_node *root);

/*********************RECURSIVE***************************/
// PRINTING
void	preorder_print(t_node *root);
void	inorder_print(t_node *root);
void	postorder_print(t_node *root);

/*********************************************************/

#endif