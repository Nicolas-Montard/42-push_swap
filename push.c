/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:44:33 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/13 11:11:48 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include "headers/list_utils.h"
#include "headers/stack.h"
#include <stdlib.h>

int	pa(t_stack *a, t_stack *b)
{
	if (b->head == NULL)
		return (1);
	if (!add_node(a, b->head->value))
		return (0);
	remove_node(b, b->head);
	ft_printf("pa\n");
	return (1);
}

int	pb(t_stack *b, t_stack *a)
{
	if (a->head == NULL)
		return (1);
	if (!add_node(b, a->head->value))
		return (0);
	remove_node(a, a->head);
	ft_printf("pb\n");
	return (1);
}
