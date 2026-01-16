/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:00:07 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/16 15:11:23 by aslimani         ###   ########.fr       */
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

int	selection_sort(t_stacks *stack)
{
	int	index_min;

	while (stack->a->size > 0)
	{
		index_min = find_min_node(stack->a);
		if (index_min <= stack->a->size / 2)
			loop_rotate(stack, index_min);
		else
			loop_reverse_rotate(stack, index_min);
		if (!pb(stack))
			return (0);
	}
	while (stack->b->size > 0)
	{
		if (!pa(stack))
			return (0);
	}
	return (1);
}
