/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:00:01 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/05 12:24:55 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/list_utils.h"
#include "headers/stack.h"
#include <stdlib.h>

void	rra(t_stack *a)
{
	t_node	*last_node;

	if (a->size < 2)
		return ;
	last_node = get_last_assigned_node(a);
	if (a->head->previous == NULL)
	{
		a->head->previous->value = last_node->value;
		last_node->value = NULL;
	}
	a->head = a->head->previous;
}

void	rrb(t_stack *b)
{
	t_node	*last_node;

	if (b->size < 2)
		return ;
	last_node = get_last_assigned_node(b);
	if (b->head->previous == NULL)
	{
		b->head->previous->value = last_node->value;
		last_node->value = NULL;
	}
	b->head = b->head->previous;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
