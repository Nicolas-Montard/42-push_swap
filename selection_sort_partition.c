/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort_partition.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:43:58 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/13 13:22:42 by nmontard         ###   ########.fr       */
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

static int	sort_to_b(t_stack *a, t_stack *b, int size_a, int *size_b)
{
	int	index_i;
	int	index_min;

	index_i = 0;
	while (size_a > 0)
	{
		index_min = find_min_node(a, size_a, index_i);
		while (index_i < index_min)
		{
			ra(a);
			index_i++;
		}
		while (index_i > index_min)
		{
			rra(a);
			index_i--;
		}
		if (!pb(b, a))
			return (0);
		size_a--;
		*size_b += 1;
	}
	return (1);
}

int	selection_sort_partition(t_stack *a, t_stack *b, int size_a)
{
	int	size_b;

	size_b = 0;
	if (!sort_to_b(a, b, size_a, &size_b))
		return (0);
	while (size_b > 0)
	{
		if (!pa(a, b))
			return (0);
		size_b--;
	}
	return (1);
}
