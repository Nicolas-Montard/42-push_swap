/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimani2 <slimani2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:44:33 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/05 14:04:46 by slimani2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include <stdlib.h>

void	pa(t_stack *a, t_stack *b)
{
	if (b->head->value == NULL)
		return ;
	a->head->previous->value = b->head->value;
	a->head = a->head->previous;
	b->head->value = NULL;
	b->head = b->head->next;
	a->size += 1;
	b->size -= 1;
}

void	pb(t_stack *b, t_stack *a)
{
	if (a->head->value == NULL)
		return ;
	b->head->previous->value = a->head->value;
	b->head = b->head->previous;
	a->head->value = NULL;
	a->head = a->head->next;
	b->size += 1;
	a->size -= 1;
}