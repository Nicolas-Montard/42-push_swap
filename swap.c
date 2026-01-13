/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:48:07 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/13 15:05:22 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include "headers/ft_printf.h"

void	sa(t_stack *stack)
{
	int	temp;

	if (stack->size < 2)
		return ;
	temp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = temp;
	ft_printf("sa\n");
}

void	sb(t_stack *stack)
{
	int	temp;

	if (stack->size < 2)
		return ;
	temp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = temp;
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	//ft_printf("ss\n");
}
