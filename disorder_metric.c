/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimani2 <slimani2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:49:15 by slimani2          #+#    #+#             */
/*   Updated: 2026/01/05 18:48:21 by slimani2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include <stdlib.h>

int     compute_disorder(t_stack *a)
{
    int     mistakes;
    int     total_pairs;
    int     index_i;
    int     index_j;
    t_node *i;
    t_node *j;
    
    index_i = 0;
    mistakes = 0;
    total_pairs = 0;
    i = a->head;
    if(a->size < 2)
        return 0;
    while(index_i < a->size)
    {
        j = i->next;
        index_j = index_i + 1;
        while(index_j < a->size)
        {
            if(i->value > j->value)
                mistakes++;
            total_pairs++;
            j = j->next;
            index_j++;
        }
        i = i->next;
        index_i++;
    }
    return ((double)mistakes / total_pairs);
}
