/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:34:33 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/13 12:24:57 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/quick_sort.h"
#include "headers/stack.h"
#include <stdlib.h>

static void	sort_stack_a(t_stack *stack_a, t_stack *stack_b, int size_a);

static void	sort_stack_b(t_stack *stack_a, t_stack *stack_b, int size_b);

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

static void	sort_stack_a(t_stack *stack_a, t_stack *stack_b, int size_a)
{
	int	pivot;
	int	i;
	int	size_b;

	size_b = 0;
	i = 0;
	if (size_a < 2)
		return ;
	if (size_a < 5)
	{
		selection_sort_partition(stack_a, stack_b, size_a);
		return ;
	}
	pivot = get_pivot_from_partition(stack_a, size_a);
	__builtin_printf("pivot A :%d\n\n", pivot);
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
	size_a--;
	while (i < size_a)
	{
		rra(stack_a);
		i++;
	}
	sort_stack_a(stack_a, stack_b, size_a);
	pa(stack_a, stack_b);
	sort_stack_b(stack_a, stack_b, size_b);
}

static void	sort_stack_b(t_stack *stack_a, t_stack *stack_b, int size_b)
{
	int	pivot;
	int	i;
	int	size_a;

	size_a = 0;
	i = 0;
	if (size_b < 1)
		return ;
	if (size_b < 5)
	{
		selection_sort_partition_one_way(stack_a, stack_b, size_b);
		return ;
	}
	pivot = get_pivot_from_partition(stack_b, size_b);
	__builtin_printf("pivot B :%d\n", pivot);
	while (stack_b->head->value != pivot)
	{
		if (stack_b->head->value > pivot)
		{
			pa(stack_a, stack_b);
			size_a++;
			size_b--;
		}
		else
			rb(stack_b);
	}
	sort_stack_a(stack_a, stack_b, size_a);
	pa(stack_a, stack_b);
	size_b--;
	while (i < size_b)
	{
		rrb(stack_b);
		i++;
	}
	sort_stack_b(stack_a, stack_b, size_b);
}

// TODO add securisation
void	quick_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	pivot;

	pivot = stack_a->head->previous->value;
	__builtin_printf("pivot A originel :%d\n\n", pivot);
	while (stack_a->head->value != pivot)
	{
		if (stack_a->head->value < pivot)
			pb(stack_b, stack_a);
		else
			ra(stack_a);
	}
	pb(stack_b, stack_a);
	sort_stack_a(stack_a, stack_b, stack_a->size);
	pa(stack_a, stack_b);
	sort_stack_b(stack_a, stack_b, stack_b->size);
}
