#include "../header.h"

t_q_node	*new_q_node(t_node *node)
{
	t_q_node	*new;

	new = (t_q_node *) malloc(sizeof(t_q_node));
	if (!new)
		error ("allocation error");
	new->content = node;
	new->next = NULL;
	return (new);
}

t_queue	*new_queue(t_node *node)
{
	t_queue	*q;

	q = (t_queue *) malloc(sizeof(t_queue));
	if (!q)
		error ("allocation error");
	q->head = NULL;
	q->tail = NULL;
	q->size = 0;
	if (node)
		push (q, node);
	return (q);
}

t_q_node	*pop(t_queue *q)
{
	t_q_node	*node;

	if (!q->head)
		return (NULL);
	node = q->head;
	q->head = (q->head)->next;
	node->next = NULL;
	q->size--;
	if (!q->head)
		q->tail = NULL;
	return (node);
}

void	push(t_queue *q, t_node *content)
{
	t_q_node	*new;

	new = new_q_node(content);
	q->size++;
	if (!q->head)
	{
		q->head = new;
		q->tail = new;
		return ;
	}
	(q->tail)->next = new;
	q->tail = new;
}

void	multiple_push(t_queue *q, int size, ...)
{
	int		i;
	va_list	args;

	i = -1;
	va_start(args, size);
	while (++i < size)
		push(q, va_arg(args, t_node *));
	va_end(args);
}
