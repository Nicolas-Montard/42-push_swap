/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:35:03 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/16 12:25:21 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include "headers/list_utils.h"
#include "headers/stack.h"
#include <stdlib.h>

void	ra(t_stacks *stack)
{
	if (stack->a->size > 1)
		stack->a->head = stack->a->head->next;
	stack->bench->op_ra += 1;
	stack->bench->op_total += 1;
	ft_printf("ra\n");
}

void	rb(t_stacks *stack)
{
	if (stack->b->size > 1)
		stack->b->head = stack->b->head->next;
	stack->bench->op_rb += 1;
	stack->bench->op_total += 1;
	ft_printf("rb\n");
}

void	rr(t_stacks *stack)
{
	if (stack->a->size > 1)
		stack->a->head = stack->a->head->next;
	if (stack->b->size > 1)
		stack->b->head = stack->b->head->next;
	stack->bench->op_rr += 1;
	stack->bench->op_total += 1;
	ft_printf("rr\n");
}
