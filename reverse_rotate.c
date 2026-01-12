/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2026/01/05 13:34:58 by slimani2          #+#    #+#             */
/*   Updated: 2026/01/12 10:56:46 by aslimani         ###   ########.fr       */
=======
/*   Created: 2026/01/05 13:34:58 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/06 14:50:45 by aslimani         ###   ########.fr       */
>>>>>>> 03497b2 (merge solved)
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
