/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:50:11 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/12 12:50:38 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/quick_sort.h"
#include "headers/stack.h"

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
	return (current_node->value);
}
