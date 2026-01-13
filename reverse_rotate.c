/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:02:03 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/13 16:50:18 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include "headers/ft_printf.h"
#include <stdlib.h>
#include "headers/ft_printf.h"

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
	rra(a);
	rrb(b);
	//ft_printf("rrr\n");
}
