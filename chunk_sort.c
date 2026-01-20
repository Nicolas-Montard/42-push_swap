/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:01:05 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/20 10:14:34 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/chunk_sort.h"

////allows you to normalize the values ​​so they can be compared to the chunks

static void	normalize_stack_a(t_stack *a)
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

int	push_to_stacka_b(t_stacks *stacks, int min, int max)
{
	int		index_chunk;

	while (still_in_a(stacks->a, min, max))
	{
		index_chunk = find_closest_value_chunk(stacks->a, min, max);
		if (index_chunk == -1)
			break ;
		if (index_chunk <= stacks->a->size / 2)
			loop_rotate(stacks, index_chunk, 'a');
		else
			loop_reverse_rotate(stacks, index_chunk, 'a');
		if (!pb(stacks))
			return (0);
	}
	return (1);
}
//finds the maximum node of the stack

static int	find_max_node(t_stack *b)
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

static int	push_stackb_to_a(t_stacks *stacks)
{
	int		index_max;

	while (stacks->b->size > 0)
	{
		index_max = find_max_node(stacks->b);
		if (index_max <= stacks->b->size / 2)
			loop_rotate(stacks, index_max, 'b');
		else
			loop_reverse_rotate(stacks, index_max, 'b');
		if (!pa(stacks))
			return (0);
	}
	return (1);
}

int	chunk_sort(t_stacks *stacks)
{
	int	chunk_size;
	int	total_chunk;

	normalize_stack_a(stacks->a);
	chunk_size = count_chunk_size(stacks->a);
	total_chunk = stacks->a->size / chunk_size;
	if (stacks->a->size % chunk_size != 0)
		total_chunk++;
	if (!push_chunk_to_b(stacks, total_chunk, chunk_size))
		return (0);
	if (!push_stackb_to_a(stacks))
		return (0);
	return (1);
}
