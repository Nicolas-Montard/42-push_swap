/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:01:05 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/13 16:49:45 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include <stdlib.h>
#include "headers/medium.h"

////allows you to normalize the values ​​so they can be compared to the chunks

static	void	normalize_stack_a(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	int		index_i;
	int		index_j;
	int		rank;

	i = a->head;
	index_i = 0;
	while (index_i < a->size)
	{
		j = a->head;
		index_j = 0;
		rank = 0;
		while (index_j < a->size)
		{
			if (i->value > j->value)
				rank++;
			j = j->next;
			index_j++;
		}
		i->index = rank;
		i = i->next;
		index_i++;
	}
}

//pushes all chunk values ​​into b

void	push_to_stacka_b(t_stack *a, t_stack *b, int min, int max)
{
	int		index_chunk;

	while (still_in_a(a, min, max))
	{
		index_chunk = find_closest_value_chunk(a, min, max);
		if (index_chunk == -1)
			break ;
		if (index_chunk <= a->size / 2)
			loop_rotate(a, index_chunk, 'a');
		else
			loop_reverse_rotate(a, index_chunk, 'a');
		pb(b, a);
	}
}
//finds the maximum node of the stack

static	int	find_max_node(t_stack *b)
{
	t_node	*i;
	t_node	*max_node;
	int		index_i;
	int		max_index;

	i = b->head;
	max_node = b->head;
	index_i = 0;
	max_index = 0;
	while (index_i < b->size)
	{
		if (i->value > max_node->value)
		{
			max_node = i;
			max_index = index_i;
		}
		i = i->next;
		index_i++;
	}
	return (max_index);
}

static	void	push_stackb_to_a(t_stack *a, t_stack *b)
{
	int		index_max;

	while (b->size > 0)
	{
		index_max = find_max_node(b);
		if (index_max <= b->size / 2)
			loop_rotate(b, index_max, 'b');
		else
		{
			loop_reverse_rotate(b, index_max, 'b');
		}
		pa(a, b);
	}
}

void	medium_sort(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	total_chunk;

	normalize_stack_a(a);
	chunk_size = count_chunk_size(a);
	total_chunk = a->size / chunk_size;
	if (a->size % chunk_size != 0)
		total_chunk++;
	push_chunk_to_b(a, b, total_chunk, chunk_size);
	push_stackb_to_a(a, b);
}
