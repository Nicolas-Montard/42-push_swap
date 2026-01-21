/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:33:16 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/21 14:04:26 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/chunk_sort.h"
#include "headers/quick_sort.h"
#include "headers/selection_sort.h"
#include "headers/stack.h"

int	adaptative(t_stacks *stacks)
{
	float	value;
	int		result;

	result = 1;
	value = stacks->bench->disorder_metric;
	if (value < 0.2)
		result = selection_sort(stacks);
	else if (value < 0.5)
		result = chunk_sort(stacks);
	else
		result = quick_sort(stacks);
	return (result);
}
