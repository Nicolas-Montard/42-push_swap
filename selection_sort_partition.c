/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort_partition.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:43:58 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/19 17:30:17 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include <stdlib.h>

static int	find_min_node(t_stack *a, int size, int index_i)
{
	t_node	*i;
	t_node	*min_node;
	int		min_index;

	i = a->head;
	while (index_i > 0)
	{
		i = i->previous;
		index_i--;
	}
	min_node = i;
	min_index = 0;
	while (index_i < size)
	{
		if (i->value < min_node->value)
		{
			min_node = i;
			min_index = index_i;
		}
		i = i->next;
		index_i++;
	}
	return (min_index);
}

static int	sort_to_b(t_stacks *stacks, int size_a, int *size_b)
{
	int	index_i;
	int	index_min;

	index_i = 0;
	while (size_a > 0)
	{
		index_min = find_min_node(stacks->a, size_a, index_i);
		while (index_i < index_min)
		{
			ra(stacks);
			index_i++;
		}
		while (index_i > index_min)
		{
			rra(stacks);
			index_i--;
		}
		if (!pb(stacks))
			return (0);
		size_a--;
		*size_b += 1;
	}
	return (1);
}

int	selection_sort_partition(t_stacks *stacks, int size_a)
{
	int	size_b;

	size_b = 0;
	if (!sort_to_b(stacks, size_a, &size_b))
		return (0);
	while (size_b > 0)
	{
		if (!pa(stacks))
			return (0);
		size_b--;
	}
	return (1);
}
