/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:35:03 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/05 11:42:04 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/list_utils.h"
#include "headers/stack.h"
#include <stdlib.h>

// innefective, will need to change
void	ra(t_stack *a)
{
	t_node	*last_node;

	if (a->size < 2)
		return ;
	last_node = get_last_assigned_node(a);
	if (last_node->next->value == NULL)
	{
		last_node->next->value = a->head->value;
		a->head->value = NULL;
	}
	a->head = a->head->next;
}

void	rb(t_stack *b)
{
	t_node	*last_node;

	if (b->size < 2)
		return ;
	last_node = get_last_assigned_node(b);
	if (last_node->next->value == NULL)
	{
		last_node->next->value = b->head->value;
		b->head->value = NULL;
	}
	b->head = b->head->next;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
