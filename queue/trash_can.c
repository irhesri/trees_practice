#include "../header.h"

void	free_queue(t_queue *q)
{
	t_q_node	*tmp;
	t_q_node	*head;

	q->tail = NULL;
	head = q->head;
	while (head)
	{
		tmp = head->next;
		free (head);
		head = tmp;
	}
	free (q);
}