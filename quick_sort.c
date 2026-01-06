/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:34:33 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/06 15:07:38 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include <stdlib.h>

int	get_pivot_from_partition(t_stack *stack, int size)
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
	return (*current_node->value);
}

// void	sort_with_partioning(t_stack *stack_a, t_stack *stack_b, int size_a,
// 		int size_b)
// {
// 	int	pivot;
// 	int	rotate_counter;

// 	// value of condition could change to use the most effective, need test
// 	// could be interresting to change for disorder metric based
// 	if (size_a < 6 && size_a > 0)
// 	{
// 		// TODO use simple algo like insertion sort
// 		return ;
// 	}
// 	if (size_b < 6 && size_b > 0)
// 	{
// 		// either sort from the other side or push all to size_a
// 		return ;
// 	}
// 	if (size_a > 6)
// 	{
// 		// will need to be separated as a function
// 		while (*stack_a->head->value)
// 		{
// 			if (*stack_a->head->value < pivot)
// 			{
// 				size_a--;
// 				size_b++;
// 				pb(stack_b, stack_a);
// 			}
// 			else
// 			{
// 				rotate_counter++;				
// 				ra(stack_a);
// 			}
// 			while (rotate_counter != 0)
// 			{
// 				rra(stack_a);
// 				rotate_counter--;
// 			}
// 		}
// 		sort_with_partioning(stack_a, stack_b, size_a, size_b);
// 	}
	
// }

void	quick_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*start_node;
	int		pivot;

	pivot = get_pivot_from_partition(stack_a, stack_a->size);
	while (stack_a->head->value != pivot)
	{
		if (*stack_a->head->value < pivot)
			pb(stack_b, stack_a);
		else
			ra(stack_a);
	}
	pb(stack_b, stack_a);
}
