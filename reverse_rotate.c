/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:00:01 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/05 11:53:42 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"

void	rra(t_stack *a)
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

void	rrb(t_stack *b)
{
	int	first;
	int	i;

	if (b->size <= 1)
		return;

	first = b->array[0];
	i = 0;
	while (i < b->top)
	{
		b->array[i] = b->array[i + 1];	
		i++;
	}
	b->array[b->top] = first;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
