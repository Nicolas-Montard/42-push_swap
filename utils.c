/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:10:22 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/22 15:39:55 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

t_stacks	*inititalize_stacks(void)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (stacks == NULL)
		return (NULL);
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->bench = NULL;
	return (stacks);
}

t_bench	*init_benchmark(void)
{
	t_bench	*bench;

	bench = malloc(sizeof(t_bench));
	if (bench == NULL)
		return (NULL);
	bench->op_sa = 0;
	bench->op_sb = 0;
	bench->op_ss = 0;
	bench->op_pa = 0;
	bench->op_pb = 0;
	bench->op_ra = 0;
	bench->op_rb = 0;
	bench->op_rr = 0;
	bench->op_rra = 0;
	bench->op_rrb = 0;
	bench->op_rrr = 0;
	bench->op_total = 0;
	bench->disorder_metric = 0;
	bench->flags = 0;
	return (bench);
}
