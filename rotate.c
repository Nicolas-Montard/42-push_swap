/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimani2 <slimani2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:55:30 by slimani2          #+#    #+#             */
/*   Updated: 2026/01/05 18:48:34 by slimani2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include <stdlib.h>

void    ra(t_stack *a)
{
    if(a->size > 2)
        a->head = a->head->next;
}
void    rb(t_stack *b)
{
    if(b->size > 2)
        b->head = b->head->next;
}

void    rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
}
