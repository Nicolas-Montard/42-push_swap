/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:01:05 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/07 16:06:02 by aslimani         ###   ########.fr       */
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

int		count_chunk_size(t_stack *a)
{
	int		chunk_size;
	
	chunk_size = 0;
	while (chunk_size * chunk_size < a->size)
		chunk_size++;
	return (chunk_size);
}
//checks if a value belongs to the chunk

int		is_in_chunk(int value, int min, int max)
{
	if (value >= min && value <= max)
		return (1);
	return (0);
}
//check if there are any chunk values ​​left in A

int		still_in_a(t_stack *a, int min, int max)
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
	int		index_chunk;
	//int		index;
	int		l;

	i = a->head;
	index_chunk = 0;
	while (still_in_a(a, min, max))
	{
		if (is_in_chunk(i->value, min, max))
		{
			if(index_chunk <= a->size / 2)
			{
				l = 0;
				while (index_chunk < a->size)
				{
					ra(a);
					l++;
				}
			}
			else
			{
				l = 0;
				while (index_chunk - a->size < a->size)
				{
					rra(a);
					l++;
				}
			}
		}
		pb(b, a);
		i = i->next;
	}
}

