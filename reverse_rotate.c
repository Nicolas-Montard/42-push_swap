/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:34:58 by slimani2          #+#    #+#             */
/*   Updated: 2026/01/12 10:56:46 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/list_utils.h"
#include "headers/stack.h"
#include <stdlib.h>

void    rra(t_stack *a)
{
    if(a->size > 1)
        a->head = a->head->previous;
}

void    rrb(t_stack *b)
{
    if(b->size > 1)
        b->head = b->head->previous;
}

void    rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
}
