#include "library.h"

void	print_list(t_list *lst)
{
	t_lst_node	*head;

	if(!lst)
		return ;
	head = lst->head;
	while (head)
	{
		if (!head->content)
			printf("NULL\t");
		else
			printf("%d\t", *((int *)(head->content)));
		head = head->next;
	}
	printf("\n");
}

t_list	*new_list(void)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	lst->head = NULL;
	lst->tail = NULL;
	lst->size = 0;
	return (lst);
}

static t_lst_node	*newnode(void *content)
{
	t_lst_node	*node;

	node = malloc(sizeof(t_lst_node));
	node->content = content;
	node->next = NULL;
	return (node);
}

void	push_back(t_list *lst, void *content)
{
	t_lst_node	*node;

	node = newnode(content);
	(lst->size)++;
	if (!lst->head)
	{
		lst->head = node;
		lst->tail = node;
		return ;
	}
	(lst->tail)->next = node;
	lst->tail = node;
}

t_lst_node	*pop_front(t_list *lst)
{
	t_lst_node	*first;

	if (!lst->head)
		return (NULL);
	first = lst->head;
	lst->head = (lst->head)->next;
	first->next = NULL;
	(lst->size)--;
	if (!lst->head)
		lst->tail = NULL;
	return (first);
}