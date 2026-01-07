/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort_partition_one_way.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:07:48 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/08 12:49:40 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include <stdlib.h>

static int	find_max_node(t_stack *b, int size)
{
	t_node	*i;
	t_node	*max_node;
	int		index_i;
	int		max_index;

	i = b->head;
	max_node = b->head;
	index_i = 0;
	max_index = 0;
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

void	selection_sort_partition_one_way(t_stack *a, t_stack *b, int size_b)
{
	int index_i;
	int index_max;

	while (size_b > 0) // while a is not empty
	{
		index_i = 0;
		index_max = find_max_node(b, size_b);
		while (index_i < index_max)
		{
			rb(b);
			index_i++;
		}
		size_b--;
		pa(a, b);
		while (index_i > 0)
		{
			rrb(b);
			index_i--;
		}
	}
}