/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:00:01 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/16 12:27:07 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include "headers/stack.h"
#include <stdlib.h>

void	rra(t_stacks *stack)
{
	if (stack->a->size > 1)
		stack->a->head = stack->a->head->previous;
	stack->bench->op_rra += 1;
	stack->bench->op_total += 1;
	ft_printf("rra\n");
}

void	rrb(t_stacks *stack)
{
	if (stack->b->size > 1)
		stack->b->head = stack->b->head->previous;
	stack->bench->op_rrb += 1;
	stack->bench->op_total += 1;
	ft_printf("rrb\n");
}

void	rrr(t_stacks *stack)
{
	if (stack->a->size > 1)
		stack->a->head = stack->a->head->previous;
	if (stack->b->size > 1)
		stack->b->head = stack->b->head->previous;
	stack->bench->op_rrr += 1;
	stack->bench->op_total += 1;
	ft_printf("rrr\n");
}
