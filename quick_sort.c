/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:34:33 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/14 14:16:44 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/quick_sort.h"
#include "headers/stack.h"
#include <stdlib.h>

static int	sort_stack_a(t_stack *stack_a, t_stack *stack_b, int size_a);

static int	sort_stack_b(t_stack *stack_a, t_stack *stack_b, int size_b);

int	split_a_to_b(t_stack *a, t_stack *b, int *size_a, int *size_b)
{
	int	pivot;
	int	i;
	int	start_size_a;

	start_size_a = *size_a;
	i = 0;
	pivot = get_median_pivot(a, *size_a);
	while (i < start_size_a)
	{
		if (a->head->value <= pivot)
		{
			if (!pb(b, a))
				return (0);
			*size_b += 1;
			*size_a -= 1;
		}
		else
			ra(a);
		i++;
	}
	i = 0;
	while (i++ < *size_a)
		rra(a);
	return (1);
}

int	split_b_to_a(t_stack *a, t_stack *b, int *size_a, int *size_b)
{
	int	pivot;
	int	i;
	int	start_size_b;

	start_size_b = *size_b;
	i = 0;
	pivot = get_median_pivot(b, *size_b);
	while (i < start_size_b)
	{
		if (b->head->value >= pivot)
		{
			if (!pa(a, b))
				return (0);
			*size_a += 1;
			*size_b -= 1;
		}
		else
			rb(b);
		i++;
	}
	return (1);
}

static int	sort_stack_a(t_stack *stack_a, t_stack *stack_b, int size_a)
{
	int	size_b;

	size_b = 0;
	if (size_a < 2)
		return (1);
	if (size_a < 16)
		return (selection_sort_partition(stack_a, stack_b, size_a));
	if (!split_a_to_b(stack_a, stack_b, &size_a, &size_b))
		return (0);
	if (!sort_stack_a(stack_a, stack_b, size_a))
		return (0);
	if (!sort_stack_b(stack_a, stack_b, size_b))
		return (0);
	return (1);
}

static int	sort_stack_b(t_stack *stack_a, t_stack *stack_b, int size_b)
{
	int	i;
	int	size_a;

	size_a = 0;
	i = 0;
	if (size_b < 1)
		return (1);
	if (size_b < 16)
		return (selection_sort_partition_one_way(stack_a, stack_b, size_b));
	if (!split_b_to_a(stack_a, stack_b, &size_a, &size_b))
		return (0);
	if (!sort_stack_a(stack_a, stack_b, size_a))
		return (0);
	while (i++ < size_b)
		rrb(stack_b);
	if (!sort_stack_b(stack_a, stack_b, size_b))
		return (0);
	return (1);
}

int	quick_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	pivot;
	int	i;
	int	start_size_a;

	start_size_a = stack_a->size;
	i = 0;
	pivot = get_median_pivot(stack_a, stack_a->size);
	while (i < start_size_a)
	{
		if (stack_a->head->value <= pivot)
		{
			if (!pb(stack_b, stack_a))
				return (0);
		}
		else
			ra(stack_a);
		i++;
	}
	if (!sort_stack_a(stack_a, stack_b, stack_a->size))
		return (0);
	if (!sort_stack_b(stack_a, stack_b, stack_b->size))
		return (0);
	return (1);
}
