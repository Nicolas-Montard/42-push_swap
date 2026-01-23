/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:39:10 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/22 15:32:30 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/benchmark.h"
#include "headers/ft_printf.h"
#include "headers/stack.h"

static char	*return_selector_from_flag(t_bench *bench)
{
	if (bench->flags[0] == 1)
		return ("Simple");
	else if (bench->flags[0] == 2)
		return ("Medium");
	else if (bench->flags[0] == 3)
		return ("Complex");
	else
		return ("Adaptive");
}

static char	*return_complexity_algo(t_bench *bench)
{
	if (bench->flags[0] == 1)
		return ("O(n^2)");
	else if (bench->flags[0] == 2)
		return ("O(n√n)");
	else if (bench->flags[0] == 3)
		return ("O(n log n)");
	else
	{
		if (bench->disorder_metric < 0.2)
			return ("O(n^2)");
		else if (bench->disorder_metric < 0.5)
			return ("O(n√n)");
		else
			return ("O(n log n)");
	}
}

void	benchmark(t_bench *bench)
{
	int		first_int;
	float	first_float;
	float	second_float;
	int		second_int;

	first_float = bench->disorder_metric * 100;
	first_int = (int)first_float;
	second_float = bench->disorder_metric * 10000;
	second_int = (int)second_float - first_int * 100;
	if (second_int == 0)
		ft_printf(2, "[bench] disorder: %d,00%\n", first_int);
	else
		ft_printf(2, "[bench] disorder: %d,%d%\n", first_int, second_int);
	ft_printf(2, "[bench] strategy: %s / %s\n",
		return_selector_from_flag(bench), return_complexity_algo(bench));
	ft_printf(2, "[bench] total_ops: %d\n", bench->op_total);
	ft_printf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", bench->op_sa,
		bench->op_sb, bench->op_ss, bench->op_pa, bench->op_pb);
	ft_printf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		bench->op_ra, bench->op_rb, bench->op_rr, bench->op_rra, bench->op_rrb,
		bench->op_rrr);
}
