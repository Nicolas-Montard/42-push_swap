/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:18:41 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/06 15:01:23 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include <stdlib.h>

t_node	*get_last_node(t_stack *stack)
{
	t_node	*node;
	t_node	*start_node;

	start_node = stack->head;
	node = stack->head;
	while (node != NULL)
	{
		if (node->next == start_node)
			break ;
		node = node->next;
	}
	return (node);
}

t_node	*add_node(t_stack *stack, int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	if (stack->head)
	{
		node->next = stack->head;
		node->previous = stack->head->previous;
		stack->head->previous->next = node;
		stack->head->previous = node;
	}
	else
	{
		node->next = node;
		node->previous = node;
	}
	stack->head = node;
	stack->size += 1;
	return (node);
}

void	remove_node(t_stack *stack, t_node *node)
{
	if (node->previous != node)
		node->previous->next = node->next;
	if (node->next != node)
		node->next->previous = node->previous;
	else
		node->next = NULL;
	stack->head = node->next;
	stack->size -= 1;
}
