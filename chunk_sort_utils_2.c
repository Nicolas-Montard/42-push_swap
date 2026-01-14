/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:57:48 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/14 12:02:01 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "headers/chunk_sort.h"

int	push_chunk_to_b(t_stack *a, t_stack *b, int total_chk, int chk_size)
{
	int	current_chunk;
	int	min;
	int	max;
	int	size_a;

	size_a = a->size;
	current_chunk = 0;
	while (current_chunk < total_chk)
	{
		min = current_chunk * chk_size;
		max = min + chk_size - 1;
		if (max >= size_a)
			max = size_a - 1;
		if (!push_to_stacka_b(a, b, min, max))
			return (0);
		current_chunk++;
	}
	return (1);
}

int	find_closest_value_chunk(t_stack *a, int min, int max)
{
	t_node	*i;
	int		index;
	int		index_chunk;

	i = a->head;
	index = 0;
	index_chunk = -1;
	while (index < a->size)
	{
		if (is_in_chunk(i->index, min, max))
		{
			index_chunk = index;
			break ;
		}
		i = i->next;
		index++;
	}
	return (index_chunk);
}
