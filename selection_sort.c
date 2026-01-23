/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:00:07 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/23 16:33:41 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/selection_sort.h"
#include "headers/utils_algo.h"

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

static int	less_action(t_stacks *stack)
{
	t_node	*i;
	int		index;
	int		index_max;

	index = 0;
	i = stack->a->head->next;
	index_max = find_max_node(stack->a) + 1;
	while (index < index_max && index_max != 0)
	{
		ra(stack);
		index++;
	}
	if (stack->a->head->value > stack->a->head->next->value)
		sa(stack);
	return (1);
}

int	selection_sort(t_stacks *stacks)
{
	int	index_min;

	if (stacks->a->size == 3)
		return (less_action(stacks));
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
