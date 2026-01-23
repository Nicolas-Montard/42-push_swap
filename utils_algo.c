/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:32:17 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/23 16:33:52 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/utils_algo.h"

int	find_max_node(t_stack *stack)
{
	t_node	*i;
	t_node	*max_node;
	int		index_i;
	int		max_index;

	i = stack->head;
	max_node = stack->head;
	index_i = 0;
	max_index = 0;
	while (index_i < stack->size)
	{
		if (i->value > max_node->value)
		{
			max_node = i;
			max_index = index_i;
		}
		i = i->next;
		index_i++;
	}
	return (max_index);
}

int	find_min_node(t_stack *a)
{
	t_node	*i;
	t_node	*min_node;
	int		index_i;
	int		min_index;

	i = a->head;
	min_node = a->head;
	index_i = 0;
	min_index = 0;
	while (index_i < a->size)
	{
		if (i->value < min_node->value)
		{
			min_node = i;
			min_index = index_i;
		}
		i = i->next;
		index_i++;
	}
	return (min_index);
}
