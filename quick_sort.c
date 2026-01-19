/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:34:33 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/19 16:06:55 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/quick_sort.h"
#include "headers/stack.h"
#include <stdlib.h>

static int	sort_stack_a(t_stacks *stack, int size_a);

static int	sort_stack_b(t_stacks *stack, int size_b);

int	split_a_to_b(t_stacks *stack, int *size_a, int *size_b)
{
	int	pivot;
	int	i;
	int	start_size_a;

	start_size_a = *size_a;
	i = 0;
	pivot = get_median_pivot(stack->a, *size_a);
	while (i < start_size_a)
	{
		if (stack->a->head->value <= pivot)
		{
			if (!pb(stack))
				return (0);
			*size_b += 1;
			*size_a -= 1;
		}
		else
			ra(stack);
		i++;
	}
	i = 0;
	while (i++ < *size_a)
		rra(stack);
	return (1);
}

int	split_b_to_a(t_stacks *stack, int *size_a, int *size_b)
{
	int	pivot;
	int	i;
	int	start_size_b;

	start_size_b = *size_b;
	i = 0;
	pivot = get_median_pivot(stack->b, *size_b);
	while (i < start_size_b)
	{
		if (stack->b->head->value >= pivot)
		{
			if (!pa(stack))
				return (0);
			*size_a += 1;
			*size_b -= 1;
		}
		else
			rb(stack);
		i++;
	}
	return (1);
}

static int	sort_stack_a(t_stacks *stack, int size_a)
{
	int	size_b;

	size_b = 0;
	if (size_a < 2)
		return (1);
	if (size_a < 16)
		return (selection_sort_partition(stack, size_a));
	if (!split_a_to_b(stack, &size_a, &size_b))
		return (0);
	if (!sort_stack_a(stack, size_a))
		return (0);
	if (!sort_stack_b(stack, size_b))
		return (0);
	return (1);
}

static int	sort_stack_b(t_stacks *stack, int size_b)
{
	int	i;
	int	size_a;

	size_a = 0;
	i = 0;
	if (size_b < 1)
		return (1);
	if (size_b < 16)
		return (selection_sort_partition_one_way(stack, size_b));
	if (!split_b_to_a(stack, &size_a, &size_b))
		return (0);
	if (!sort_stack_a(stack, size_a))
		return (0);
	while (i++ < size_b)
		rrb(stack);
	if (!sort_stack_b(stack, size_b))
		return (0);
	return (1);
}

int	quick_sort(t_stacks *stack)
{
	int	pivot;
	int	i;
	int	start_size_a;

	start_size_a = stack->a->size;
	i = 0;
	pivot = get_median_pivot(stack->a, stack->a->size);
	while (i < start_size_a)
	{
		if (stack->a->head->value <= pivot)
		{
			if (!pb(stack))
				return (0);
		}
		else
			ra(stack);
		i++;
	}
	if (!sort_stack_a(stack, stack->a->size))
		return (0);
	if (!sort_stack_b(stack, stack->b->size))
		return (0);
	return (1);
}
