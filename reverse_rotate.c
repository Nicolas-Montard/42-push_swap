/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:00:01 by aslimani          #+#    #+#             */
/*   Updated: 2025/12/15 16:54:19 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"

void	rra(t_stack *a)
{
	int	first;
	int	i;

	if (a->size <= 1)
		return;

	first = a->array[0];
	i = 0;
	while (i < a->top)
	{
		a->array[i] = a->array[i + 1];	
		i++;
	}
	a->array[a->top] = first;
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
