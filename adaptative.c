/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:33:16 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/19 17:50:19 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/disorder_metric.h"

void	adaptative(t_stacks *stacks)
{
	float	value;

	value = compute_disorder(stacks->a);
	if (value < 0.2)
		selection_sort(stacks);
	else if (value <= 0.2 && value < 0.5)
		chunk_sort(stacks);
	else if (value >= 0.5)
		quick_sort(stacks);
	else
		return ;
}
