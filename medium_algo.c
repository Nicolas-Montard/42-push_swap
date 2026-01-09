/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:01:05 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/09 11:26:01 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include <stdlib.h>
#include "headers/medium.h"

////allows you to normalize the values ​​so they can be compared to the chunks
void	normalize_stack_a(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	int		index_i;
	int		index_j;
	int		rank;

	i = a->head;
	j = a->head;
	index_i = 0;
	while (index_i < a->size)
	{
		index_j = 0;
		rank = 0;
		while (index_j < a->size)
		{
			if (i->value > j->value)
				rank++;
			j = j->next;
			index_j++;
		}
		i->value = rank;
		i = i->next;
		index_i++;
	}
}
//calculate the square root of n elements

int	count_chunk_size(t_stack *a)
{
	int		chunk_size;

	chunk_size = 0;
	while (chunk_size * chunk_size < a->size)
		chunk_size++;
	return (chunk_size);
}
//checks if a value belongs to the chunk

int	is_in_chunk(int value, int min, int max)
{
	if (value >= min && value <= max)
		return (1);
	return (0);
}
//check if there are any chunk values ​​left in A

int	still_in_a(t_stack *a, int min, int max)
{
	t_node	*i;
	int		index_i;

	i = a->head;
	index_i = 0;
	while (index_i < a->size)
	{
		if (is_in_chunk(i->value, min, max))
			return (1);
		i = i->next;
		index_i++;
	}
	return (0);
}
//pushes all chunk values ​​into b

void	push_to_stack_b(t_stack *a, t_stack *b, int min, int max)
{
	t_node	*i;
	int		index;
	int		index_chunk;
	int		l;

	while (stil_in_stack_a(a, min, max))
	{
		i = a->head;
		index = 0;
		index_chunk = -1;
		while (index < a->size)
		{
			if (is_in_chunk(i->value, min, max))
			{
				index_chunk = index;
				break ;
			}
			i = i->next;
			index++;
		}
		if (index_chunk == -1)
			break ;
		if (index_chunk <= a->size / 2)
		{
			l = 0;
			while (l < index_chunk)
			{
				ra(a);
				l++;
			}
		}
		else
		{
			l = 0;
			while (l < a->size - index_chunk)
			{
				rra(a);
				l++;
			}
		}
		pb(b, a);
	}
}
//finds the maximum node of the stack

int	find_max_node(t_stack *b)
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

void	push_stackb_to_a(t_stack *a, t_stack *b)
{
	int		index;
	int		index_max;
	int		r;

	while (b->size > 0)
	{
		index = 0;
		index_max = find_max_node(b);
		if (index_max <= b->size / 2)
		{
			while (index < index_max)
			{
				rb(b);
				index++;
			}
		}
		else
		{
			r = b->size - index_max;
			while (r > 0)
			{
				rrb(b);
				r--;
			}
		}
		pa(a, b);
	}
}

void	medium_sort(t_stack *a, t_stack *b)
{
	int	min;
	int	max;
	int	chunk_size;
	int	current_chunk;
	int	total_chunk;

	current_chunk = 0;
	normalize_stack_a(a);
	chunk_size = count_chunk_size(a);
	total_chunk = a->size / chunk_size;
	if (a->size % chunk_size != 0)
		total_chunk++;
	while (current_chunk < total_chunk)
	{
		min = current_chunk * chunk_size;
		max = min + chunk_size - 1;
		if (max >= a->size)
			max = a->size - 1;
		push_to_stack_b(a, b, min, max);
		current_chunk++;
	}
	push_stackb_to_a(a, b);
}
