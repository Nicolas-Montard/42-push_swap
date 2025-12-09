/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:48:07 by nmontard          #+#    #+#             */
/*   Updated: 2025/12/09 13:29:08 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(stack *stack)
{
	int	temp;

	if (stack->top < 1)
		return ;
	temp = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = temp;
}

void	ss(stack *a, stack *b)
{
	swap(a);
	swap(b);
}
