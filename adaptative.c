/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:33:16 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/20 11:35:38 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/chunk_sort.h"
#include "headers/quick_sort.h"
#include "headers/selection_sort.h"
#include "headers/stack.h"

void	adaptative(t_stacks *stacks)
{
	float	value;

	value = stacks->bench->disorder_metric;
	if (value < 0.2)
		selection_sort(stacks);
	else if (value < 0.5)
		chunk_sort(stacks);
	else if (value >= 0.5)
		quick_sort(stacks);
	else
		return ;
}
