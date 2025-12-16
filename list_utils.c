/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:18:41 by nmontard          #+#    #+#             */
/*   Updated: 2025/12/16 15:46:15 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include <stdlib.h>

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
	node->previous = NULL;
	stack->head = node;
	return (node);
}

t_node	*get_last_node(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	while (node != NULL && node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}
