/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:34:33 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/23 15:36:33 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/quick_sort.h"
#include "headers/selection_sort.h"
#include "headers/stack.h"
#include <stdlib.h>

static int	sort_stack_a(t_stacks *stacks, int size_a);

static int	sort_stack_b(t_stacks *stacks, int size_b);

int	split_a_to_b(t_stacks *stacks, int *size_a, int *size_b)
{
	int	pivot;
	int	i;
	int	start_size_a;

	start_size_a = *size_a;
	i = 0;
	pivot = get_median_pivot(stacks->a, *size_a);
	while (i < start_size_a)
	{
		if (stacks->a->head->value <= pivot)
		{
			if (!pb(stacks))
				return (0);
			*size_b += 1;
			*size_a -= 1;
		}
		else
			ra(stacks);
		i++;
	}
	i = 0;
	while (i++ < *size_a)
		rra(stacks);
	return (1);
}

int	split_b_to_a(t_stacks *stacks, int *size_a, int *size_b)
{
	int	pivot;
	int	i;
	int	start_size_b;

	start_size_b = *size_b;
	i = 0;
	pivot = get_median_pivot(stacks->b, *size_b);
	while (i < start_size_b)
	{
		if (stacks->b->head->value >= pivot)
		{
			if (!pa(stacks))
				return (0);
			*size_a += 1;
			*size_b -= 1;
		}
		else
			rb(stacks);
		i++;
	}
	return (1);
}

static int	sort_stack_a(t_stacks *stacks, int size_a)
{
	int	size_b;

	size_b = 0;
	if (size_a < 2)
		return (1);
	if (size_a < 10)
		return (selection_sort_partition(stacks, size_a));
	if (!split_a_to_b(stacks, &size_a, &size_b))
		return (0);
	if (!sort_stack_a(stacks, size_a))
		return (0);
	if (!sort_stack_b(stacks, size_b))
		return (0);
	return (1);
}

static int	sort_stack_b(t_stacks *stacks, int size_b)
{
	int	i;
	int	size_a;

	size_a = 0;
	i = 0;
	if (size_b < 1)
		return (1);
	if (size_b < 10)
		return (selection_sort_partition_one_way(stacks, size_b));
	if (!split_b_to_a(stacks, &size_a, &size_b))
		return (0);
	if (!sort_stack_a(stacks, size_a))
		return (0);
	while (i++ < size_b)
		rrb(stacks);
	if (!sort_stack_b(stacks, size_b))
		return (0);
	return (1);
}

int	quick_sort(t_stacks *stacks)
{
	int	pivot;
	int	i;
	int	start_size_a;

	start_size_a = stacks->a->size;
	i = 0;
	if (stacks->a->size < 10)
		return (selection_sort(stacks));
	pivot = get_median_pivot(stacks->a, stacks->a->size);
	while (i < start_size_a)
	{
		if (stacks->a->head->value <= pivot)
		{
			if (!pb(stacks))
				return (0);
		}
		else
			ra(stacks);
		i++;
	}
	if (!sort_stack_a(stacks, stacks->a->size))
		return (0);
	if (!sort_stack_b(stacks, stacks->b->size))
		return (0);
	return (1);
}
