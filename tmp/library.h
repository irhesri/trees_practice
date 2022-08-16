#ifndef LIBRARY_H
# define LIBRARY_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct s_lst_node
{
	void				*content;
	struct s_lst_node	*next;
} t_lst_node;

typedef struct s_node
{
	void			*content;
	struct s_node	*left;
	struct s_node	*right;
} t_node;

typedef struct s_list
{
	int			size;
	t_lst_node	*head;
	t_lst_node	*tail;
} t_list;

// typedef struct s_tree
// {
// 	// int			size;
// 	t_lst_node	*root;
// } t_tree;

t_list	*new_list(void);
void	push_back(t_list *lst, void *content);
t_lst_node	*pop_front(t_list *lst);
void	print_list(t_list *lst);
t_node	*new_node(void *content);
void	print_tree(t_node *root);

void	print_tree_1(t_node *root);
void	print_tree_2(t_node *root);
int	get_height(t_node *root);


#endif