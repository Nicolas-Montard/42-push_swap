/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:00:01 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/14 15:44:31 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include "headers/stack.h"
#include <stdlib.h>

void	rra(t_stack *a)
{
	if (a->size > 1)
		a->head = a->head->previous;
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	if (b->size > 1)
		b->head = b->head->previous;
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a->size > 1)
		a->head = a->head->previous;
	if (b->size > 1)
		b->head = b->head->previous;
	ft_printf("rrr\n");
}
