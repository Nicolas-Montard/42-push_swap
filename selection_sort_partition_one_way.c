/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort_partition_one_way.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:07:48 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/13 14:39:15 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include <stdlib.h>

static int	find_max_node(t_stack *b, int size, int index_i)
{
	t_node	*i;
	t_node	*max_node;
	int		max_index;

	i = b->head;
	while (index_i > 0)
	{
		i = i->previous;
		index_i--;
	}
	max_index = 0;
	max_node = i;
	while (index_i < size)
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

int	selection_sort_partition_one_way(t_stack *a, t_stack *b, int size_b)
{
	int	index_i;
	int	index_max;

	index_i = 0;
	while (size_b > 0)
	{
		index_max = find_max_node(b, size_b, index_i);
		while (index_i < index_max)
		{
			rb(b);
			index_i++;
		}
		while (index_i > index_max)
		{
			rrb(b);
			index_i--;
		}
		if (!pa(a, b))
			return (0);
		size_b--;
	}
	return (1);
}
