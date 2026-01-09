/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:00:27 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/12 11:09:14 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/list_utils.h"
#include "headers/stack.h"
#include <stdlib.h>

void	ra(t_stack *a)
{
	if (a->size > 1)
		a->head = a->head->next;
}

void	rb(t_stack *b)
{
	if (b->size > 1)
		b->head = b->head->next;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
