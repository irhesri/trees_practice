#ifndef TREE_H
# define TREE_H

# include <stdbool.h>

typedef struct s_node
{
	void			*content;
	struct s_node	*right;
	struct s_node	*left;
} t_node;

// TREE OPERATIONS
t_node	*new_node(void *content);
t_node	*insert_node(t_node *root, void *content);
t_node	*bst_insertion(t_node *root, void *content);

// TREE PROPERTIES
int		get_height(t_node *root);
int		get_size(t_node *root);
int		get_depth(t_node *root, t_node *node);

// TREE TYPES
bool	is_full(t_node *root);
bool	is_complete(t_node *root);
bool	is_perfect(t_node *root);
bool	is_balanced(t_node *root);
bool	is_pathological(t_node *root);
bool	is_left_skewed(t_node *root);
bool	is_right_skewed(t_node *root);
bool	is_skewed(t_node *root);

// TREE SEARCH
t_node	*get_node(t_node *root, void *content, int (*compare)(void *, void *));
t_node	*get_parent(t_node *root, void *content, int (*compare)(void *, void *));

// TRASH CAN
void	free_tree(t_node *root);

// PRINTING
/*********************RECURSIVE***************************/
void	preorder_print(t_node *root, void (*print)(void *, const char *str));
void	inorder_print(t_node *root, void (*print)(void *, const char *str));
void	postorder_print(t_node *root, void (*print)(void *, const char *str));
/*********************************************************/

/*********************NON-RECURSIVE***********************/
void	print_tree(t_node *root, void (*print)(void *, const char *str));
void	print_tree_with_spaces(t_node *root, void (*print)(void *, const char *str));
/*********************************************************/

#endif