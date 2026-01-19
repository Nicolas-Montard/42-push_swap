/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:05:27 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/19 16:05:56 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISORDER_METRIC_H
# define DISORDER_METRIC_H

# include "stack.h"

typedef struct s_disorder
{
	float		mistakes;
	float		total_pairs;
	int			index_i;
	int			index_j;
	t_node		*i;
	t_node		*j;
}				t_disorder;

#endif