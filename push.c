/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:44:33 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/06 13:19:42 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/list_utils.h"
#include "headers/stack.h"
#include <stdlib.h>

void	pa(t_stack *a, t_stack *b)
{
	if (b->head == NULL)
		return ;
	add_node(a, b->head->value);
	remove_node(b, b->head);
}

void	pb(t_stack *b, t_stack *a)
{
	if (a->head == NULL)
		return ;
	add_node(b, a->head->value);
	remove_node(a, a->head);
}
