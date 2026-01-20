/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:39:14 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/20 11:16:59 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCHMARK_H
# define BENCHMARK_H

typedef struct s_bench
{
	int		op_sa;
	int		op_sb;
	int		op_ss;
	int		op_pa;
	int		op_pb;
	int		op_ra;
	int		op_rb;
	int		op_rr;
	int		op_rra;
	int		op_rrb;
	int		op_rrr;
	int		op_total;
	float	disorder_metric;
	int		algo_type;
}			t_bench;

void		benchmark(t_bench *bench);

#endif