/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:00:52 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/13 16:54:09 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include <stdlib.h>

int	compute_disorder(t_stack *a)
{
	int		mistakes;
	int		total_pairs;
	int		index_i;
	int		index_j;
	t_node	*i;
	t_node	*j;

	index_i = 0;
	mistakes = 0;
	total_pairs = 0;
	i = a->head;
	if (a->size < 2)
		return (0);
	while (index_i < a->size)
	{
		j = i->next;
		index_j = index_i + 1;
		while (index_j < a->size)
		{
			if (i->value > j->value)
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
