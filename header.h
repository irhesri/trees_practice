#ifndef HEADER_H
# define HEADER_H

# include "tree.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

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

// QUEUE FUNCTIONS
void		push(t_queue *q, t_node *content);
void		print_queue(t_queue *q);
void		free_queue(t_queue *q);
t_queue		*new_queue(t_node *node);
t_q_node	*pop(t_queue *q);
t_q_node	*new_q_node(t_node *node);

// OTHER FUNCTIONS
char	error(char *str);
int		max(int a, int b);
short	compare_int(void *a, void *b);

#endif