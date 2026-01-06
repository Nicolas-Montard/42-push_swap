/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimani2 <slimani2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:31:36 by slimani2          #+#    #+#             */
/*   Updated: 2026/01/05 18:48:47 by slimani2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include <stdlib.h>

static  int    find_min_node(t_stack *a)
{
    t_node *i;
    t_node *min_node;
    int     index_i;
    int     min_index;

    i = a->head;
    min_node = a->head;
    index_i = 0;
    min_index = 0;
    while(index_i < a->size)
    {
        if(i->value < min_node->value)
        {
            min_node = i;
            min_index = index_i;
        }    
        i = i->next;
        index_i++;
    }
    return(min_index);
}

void    selection_sort_adaptation(t_stack *a, t_stack *b)
{
    int     index_i;
    int     index_min;
    int     reverse;

    while(a->size > 0) // while a is not empty
    {
        index_i = 0;
        index_min = find_min_node(a);
        if(index_min <= a->size / 2)
        {
            while(index_i < index_min)
            {
                ra(a);
                index_i++;
            }
        }    
        else
        {
            reverse = a->size - index_min;
            while(reverse > 0)
            {
                rra(a);
                reverse--;
            }
        }
        pb(a, b);
    }
    while(b->size > 0)
        pa(a, b);
}

