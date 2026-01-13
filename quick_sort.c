/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:34:33 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/13 16:44:30 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/quick_sort.h"
#include "headers/stack.h"
#include <stdlib.h>

static int	sort_stack_a(t_stack *stack_a, t_stack *stack_b, int size_a);

static int	sort_stack_b(t_stack *stack_a, t_stack *stack_b, int size_b);

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

int	split_a_to_b(t_stack *a, t_stack *b, int *size_a, int *size_b)
{
	int	pivot;
	int	i;

	i = 0;
	pivot = get_pivot_from_partition(a, *size_a);
	while (a->head->value != pivot)
	{
		if (a->head->value < pivot)
		{
			if (!pb(b, a))
				return (0);
			*size_b++;
			*size_a--;
		}
		else
			ra(a);
	}
	if (!pb(b, a))
		return (0);
	*size_a--;
	while (i++ < size_a)
		rra(a);
	return (1);
}

int	split_b_to_a(t_stack *a, t_stack *b, int *size_a, int *size_b)
{
	int	pivot;
	int	i;

	i = 0;
	pivot = get_pivot_from_partition(b, *size_b);
	while (b->head->value != pivot)
	{
		if (b->head->value > pivot)
		{
			if (!pa(a, b))
				return (0);
			*size_a++;
			*size_b--;
		}
		else
			rb(b);
	}
	return (1);
}

static int	sort_stack_a(t_stack *stack_a, t_stack *stack_b, int size_a)
{
	int	pivot;
	int	size_b;

	size_b = 0;
	if (size_a < 2)
		return ;
	if (size_a < 10)
		return (selection_sort_partition(stack_a, stack_b, size_a));
	if (!split_a_to_b(stack_a, stack_b, &size_a, &size_b))
		return (0);
	if (!sort_stack_a(stack_a, stack_b, size_a))
		return (0);
	if (!pa(stack_a, stack_b))
		return (0);
	if (!sort_stack_b(stack_a, stack_b, size_b))
		return (0);
	return (1);
}

static int	sort_stack_b(t_stack *stack_a, t_stack *stack_b, int size_b)
{
	int	pivot;
	int	i;
	int	size_a;

	size_a = 0;
	i = 0;
	if (size_b < 1)
		return ;
	if (size_b < 15)
		return (selection_sort_partition_one_way(stack_a, stack_b, size_b));
	if (!split_b_to_a(stack_a, stack_b, &size_a, &size_b))
		return (0);
	if (!sort_stack_a(stack_a, stack_b, size_a))
		return (0);
	if (!pa(stack_a, stack_b))
		return (0);
	size_b--;
	while (i++ < size_b)
		rrb(stack_b);
	if (!sort_stack_b(stack_a, stack_b, size_b))
		return (0);
	return (1);
}

// TODO add securisation
void	quick_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	pivot;

	pivot = stack_a->head->previous->value;
	while (stack_a->head->value != pivot)
	{
		if (stack_a->head->value < pivot)
		{
			if (!pb(stack_b, stack_a))
				return (0);
		}
		else
			ra(stack_a);
	}
	if (!pb(stack_b, stack_a))
		return (0);
	if (!sort_stack_a(stack_a, stack_b, stack_a->size))
		return (0);
	if (!pa(stack_a, stack_b))
		return (0);
	if (!sort_stack_b(stack_a, stack_b, stack_b->size))
		return (0);
	return (1);
}
