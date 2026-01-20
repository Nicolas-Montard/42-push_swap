/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort_partition_one_way.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:07:48 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/19 17:30:53 by aslimani         ###   ########.fr       */
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

int	selection_sort_partition_one_way(t_stacks *stacks, int size_b)
{
	int	index_i;
	int	index_max;

	index_i = 0;
	while (size_b > 0)
	{
		index_max = find_max_node(stacks->b, size_b, index_i);
		while (index_i < index_max)
		{
			rb(stacks);
			index_i++;
		}
		while (index_i > index_max)
		{
			rrb(stacks);
			index_i--;
		}
		if (!pa(stacks))
			return (0);
		size_b--;
	}
	return (1);
}
