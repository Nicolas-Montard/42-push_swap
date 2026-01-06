/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:34:33 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/06 16:28:34 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include <stdlib.h>

static int	get_pivot_from_partition(t_stack *stack, int size)
{
	t_node	*current_node;
	int		counter;

	counter = 1;
	current_node = stack->head;
	while (counter < size)
	{
		current_node = current_node->next;
		counter++;
	}
	return (current_node->value);
}

void	sort_stack_a(t_stack *stack_a, t_stack *stack_b, int size_a)
{
	int	pivot;
	int	i;
	int	size_b;

	size_b = 0;
	i = 0;
	// number need to be tested to adjust them
	if (size_a < 20)
	{
		// call a function to sort small array
		return ;
	}
	pivot = get_pivot_from_partition(stack_a, size_a);
	while (stack_a->head->value != pivot)
	{
		if (stack_a->head->value < pivot)
		{
			pb(stack_b, stack_a);
			size_b++;
			size_a--;
		}
		else
			ra(stack_a);
	}
	pb(stack_b, stack_a);
	while (i < size_a)
		rra(stack_a);
	sort_stack_a(stack_a, stack_b, size_a);
	sort_stack_b(stack_a, stack_b, size_b);
}

sort_stack_b(t_stack *stack_a, t_stack *stack_b, int size_b)
{
	int	pivot;
	int	i;
	int	size_a;

	size_a = 0;
	i = 0;
	pa(stack_a, stack_b);
	// number need to be tested to adjust them
	if (size_b < 20)
	{
		// call a function to sort small array and push or just push
		return ;
	}
	pivot = get_pivot_from_partition(stack_b, size_b);
	while (stack_b->head->value != pivot)
	{
		if (stack_b->head->value < pivot)
		{
			pa(stack_a, stack_b);
			size_a++;
			size_b--;
		}
		else
			rb(stack_b);
	}
	pa(stack_b, stack_a);
	while (i < size_b)
		rrb(stack_b);
	sort_stack_a(stack_a, stack_b, size_a);
	sort_stack_b(stack_a, stack_b, size_b);
}

void	quick_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*start_node;
	int		pivot;
	int		size_b;

	size_b = 0;
	pivot = start_node->previous;
	while (stack_a->head->value != pivot)
	{
		if (stack_a->head->value < pivot)
		{
			size_b++;
			pb(stack_b, stack_a);
		}
		else
			ra(stack_a);
	}
	pb(stack_b, stack_a);
	// call left function
	// call right function
}
