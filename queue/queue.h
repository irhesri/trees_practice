#ifndef QUEUE_H
# define QUEUE_H

# include "../binary_tree/tree.h"
# include <stdio.h>

typedef struct s_q_node
{
	t_node			*content;
	struct s_q_node	*next;
} t_q_node;

typedef struct s_queue
{
	size_t		size;
	t_q_node	*head;
	t_q_node	*tail;
} t_queue;


// INITIALISATION
t_q_node	*new_q_node(t_node *node);
t_queue		*new_queue(t_node *node);

// OPERATIONS
void		push(t_queue *q, t_node *content);
void		multiple_push(t_queue *q, int size, ...);
t_q_node	*pop(t_queue *q);

// DEBUGGING
void		print_queue(t_queue *q);

// TRASH CAN
void		free_queue(t_queue *q);

#endif