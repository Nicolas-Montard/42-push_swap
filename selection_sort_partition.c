/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort_partition.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:43:58 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/08 12:31:42 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include <stdlib.h>

static int	find_min_node(t_stack *a, int size)
{
	t_node	*i;
	t_node	*min_node;
	int		index_i;
	int		min_index;

	i = a->head;
	min_node = a->head;
	index_i = 0;
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

void	selection_sort_partition(t_stack *a, t_stack *b, int size_a)
{
	int	index_i;
	int	index_min;
	int	size_b;

	size_b = 0;
	while (size_a > 0) // while a is not empty
	{
		index_i = 0;
		index_min = find_min_node(a, size_a);
		while (index_i < index_min)
		{
			ra(a);
			index_i++;
		}
		size_a--;
		size_b++;
		pb(b, a);
		while (index_i > 0)
		{
			rra(a);
			index_i--;
		}
	}
	while (size_b > 0)
	{
		pa(a, b);
		size_b--;
	}
}
