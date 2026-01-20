/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:00:07 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/19 17:31:57 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/selection_sort.h"

static	void	loop_rotate(t_stacks *stack, int index)
{
	int	r;

	r = 0;
	while (r < index)
	{
		ra(stack);
		r++;
	}
}

static	void	loop_reverse_rotate(t_stacks *stack, int index)
{
	int	rev;

	rev = 0;
	while (rev < stack->a->size - index)
	{
		rra(stack);
		rev++;
	}
}

static	int	find_min_node(t_stack *a)
{
	t_node	*i;
	t_node	*min_node;
	int		index_i;
	int		min_index;

	i = a->head;
	min_node = a->head;
	index_i = 0;
	min_index = 0;
	while (index_i < a->size)
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

int	selection_sort(t_stacks *stacks)
{
	int	index_min;

	while (stacks->a->size > 0)
	{
		index_min = find_min_node(stacks->a);
		if (index_min <= stacks->a->size / 2)
			loop_rotate(stacks, index_min);
		else
			loop_reverse_rotate(stacks, index_min);
		if (!pb(stacks))
			return (0);
	}
	while (stacks->b->size > 0)
	{
		if (!pa(stacks))
			return (0);
	}
	return (1);
}
