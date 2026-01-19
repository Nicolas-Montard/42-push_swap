/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:50:11 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/19 16:21:12 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/quick_sort.h"
#include "headers/stack.h"

static int	get_value_by_size(t_stack *stack, int size)
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

int	get_median_pivot(t_stack *stack, int size)
{
	int	start_value;
	int	middle_value;
	int	end_value;

	start_value = stack->head->value;
	middle_value = get_value_by_size(stack, size / 2);
	end_value = get_value_by_size(stack, size);
	if ((start_value < middle_value && start_value > end_value)
		|| (start_value > middle_value && start_value < end_value))
	{
		return (start_value);
	}
	else if ((end_value < middle_value && end_value > start_value)
		|| (end_value > middle_value && end_value < start_value))
	{
		return (end_value);
	}
	else
		return (middle_value);
}
