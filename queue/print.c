#include "../header.h"

void	print_queue(t_queue *q)
{
	t_q_node	*head;

	head = q->head;
	while (head)
	{
		printf("%d\t", *((int *)(head->content)->content));
		head = head->next;
	}
	printf("\n");
}