/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimani2 <slimani2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:01:12 by slimani2          #+#    #+#             */
/*   Updated: 2026/01/05 18:48:26 by slimani2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include <stdlib.h>
#include <math.h>


void    chunk_based_sorting(t_stack *a, t_stack *b)
{
    int n;
    int chunk_size;

    n = a->size;
    chunk_size = sqrt(n);
}
