/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:00:52 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/20 12:59:59 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/disorder_metric.h"

float	compute_disorder(t_stack *a)
{
	t_disorder	d;

	d.index_i = 0;
	d.mistakes = 0;
	d.total_pairs = 0;
	d.i = a->head;
	if (a->size < 2)
		return (0);
	while (d.index_i < a->size)
	{
		d.j = d.i->next;
		d.index_j = d.index_i + 1;
		while (d.index_j < a->size)
		{
			if (d.i->value > d.j->value)
				d.mistakes++;
			d.total_pairs++;
			d.j = d.j->next;
			d.index_j++;
		}
		d.i = d.i->next;
		d.index_i++;
	}
	return (d.mistakes / d.total_pairs);
}
