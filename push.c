/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:44:33 by nmontard          #+#    #+#             */
/*   Updated: 2025/12/10 12:10:44 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"

void	pa(t_stack *a, t_stack *b)
{
	a->array[a->top + 1] = b->array[b->top];
	a->top += 1;
	b->top -= 1;
}

void	pb(t_stack *b, t_stack *a)
{
	b->array[b->top + 1] = a->array[a->top];
	b->top += 1;
	a->top -= 1;
}
