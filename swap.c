/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:48:07 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/19 15:57:14 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include "headers/stack.h"

static void	swap(t_stack *stack)
{
	int	temp;

	if (stack->size < 2)
		return ;
	temp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = temp;
}

void	sa(t_stacks *stack)
{
	swap(stack->a);
	stack->bench->op_sa += 1;
	stack->bench->op_total += 1;
	ft_printf(1, "sa\n");
}

void	sb(t_stacks *stack)
{
	swap(stack->b);
	stack->bench->op_sb += 1;
	stack->bench->op_total += 1;
	ft_printf(1, "sb\n");
}

void	ss(t_stacks *stack)
{
	swap(stack->a);
	swap(stack->b);
	stack->bench->op_ss += 1;
	stack->bench->op_total += 1;
	ft_printf(1, "ss\n");
}
