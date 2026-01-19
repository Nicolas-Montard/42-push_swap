/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:44:33 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/19 12:09:59 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include "headers/list_utils.h"
#include "headers/stack.h"
#include "headers/ft_printf.h"
#include <stdlib.h>

int	pa(t_stacks *stack)
{
	if (stack->b->head == NULL)
		return (1);
	if (!add_node(stack->a, stack->b->head->value))
		return (0);
	remove_node(stack->b, stack->b->head);
	stack->bench->op_pa += 1;
	stack->bench->op_total += 1;
	ft_printf(1, "pa\n");
	return (1);
}

int	pb(t_stacks *stack)
{
	if (stack->a->head == NULL)
		return (1);
	if (!add_node(stack->b, stack->a->head->value))
		return (0);
	remove_node(stack->a, stack->a->head);
	stack->bench->op_pb += 1;
	stack->bench->op_total += 1;
	ft_printf(1, "pb\n");
	return (1);
}
