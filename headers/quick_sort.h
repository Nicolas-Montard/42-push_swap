/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:13:44 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/19 17:32:07 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICK_SORT_H
# define QUICK_SORT_H

# include "stack.h"

int	selection_sort_partition(t_stacks *stacks, int size_a);

int	selection_sort_partition_one_way(t_stacks *stacks, int size_b);

int	quick_sort(t_stacks *stacks);

int	get_median_pivot(t_stack *stacks, int size);
#endif
