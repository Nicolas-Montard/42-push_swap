/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimani2 <slimani2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:34:58 by slimani2          #+#    #+#             */
/*   Updated: 2026/01/05 18:48:30 by slimani2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include <stdlib.h>

void    rra(t_stack *a)
{
    if(a->size > 2)
        a->head = a->head->previous;
}

void    rrb(t_stack *b)
{
    if(b->size > 2)
        b->head = b->head->previous;
}

void    rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
}
