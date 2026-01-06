/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:00:07 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/06 15:14:12 by aslimani         ###   ########.fr       */
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
        pb(b, a);
    }
    while(b->size > 0)
        pa(a, b);
}

