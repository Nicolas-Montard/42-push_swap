/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:55:30 by slimani2          #+#    #+#             */
/*   Updated: 2026/01/06 14:25:41 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include <stdlib.h>

void    ra(t_stack *a)
{
    if(a->size > 1)
        a->head = a->head->next;
}
void    rb(t_stack *b)
{
    if(b->size > 1)
        b->head = b->head->next;
}

void    rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
}
