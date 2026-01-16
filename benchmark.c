/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:39:10 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/16 11:21:06 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/benchmark.h"
#include "headers/stack.h"
#include "headers/ft_printf.h"

void	benchmark(char *selector, char *algo, t_bench *bench)
{
	ft_printf("[bench] disorder: %d%\n", bench->disorder_metric);
	ft_printf("[bench] strategy: %s / %s\n", selector, algo);
	ft_printf("[bench] total_ops: %d\n", bench->op_total);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", bench->op_sa, bench->op_sb, bench->op_ss, bench->op_pa, bench->op_pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", bench->op_ra, bench->op_rb, bench->op_rr, bench->op_rra, bench->op_rrb, bench->op_rrr);
}
