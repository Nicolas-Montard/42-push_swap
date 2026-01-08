/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:13:44 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/07 15:29:24 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICK_SORT_H
# define QUICK_SORT_H

# include "stack.h"

void	selection_sort_partition(t_stack *a, t_stack *b, int size_a);

void	selection_sort_partition_one_way(t_stack *a, t_stack *b, int size_b);

void	quick_sort(t_stack *stack_a, t_stack *stack_b);

#endif
