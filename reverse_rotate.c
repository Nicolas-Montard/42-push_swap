/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:02:03 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/12 11:09:09 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include <stdlib.h>

void	rra(t_stack *a)
{
	if (a->size > 1)
		a->head = a->head->previous;
}

void	rrb(t_stack *b)
{
	if (b->size > 1)
		b->head = b->head->previous;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
