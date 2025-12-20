/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:18:41 by nmontard          #+#    #+#             */
/*   Updated: 2025/12/20 13:57:05 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include <stdlib.h>

t_node	*get_last_node(t_stack *stack)
{
	t_node	*node;
	t_node	*start_node;
	int		started;

	started = 0;
	start_node = stack->head;
	node = stack->head;
	while (node != NULL)
	{
		if (node->next == NULL || node->next == start_node)
			break ;
		node = node->next;
	}
	return (node);
}

t_node	*add_node(t_stack *stack, int *value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	if (stack->head)
		stack->head->previous = node;
	node->value = value;
	node->next = stack->head;
	node->previous = get_last_node(stack);
	stack->head = node;
	return (node);
}

t_node	*add_node_last(t_stack *stack, int *value)
{
	t_node *node;
	t_node *previous_node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = stack->head;
	previous_node = get_last_node(stack);
	node->previous = previous_node;
	if (previous_node == NULL)
	{
		stack->head = node;
		return (node);
	}
	previous_node->next = node;
	stack->head->previous = node;
	return (node);
}
