/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:07:21 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/14 12:07:26 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNK_SORT_H
# define CHUNK_SORT_H

#include "stack.h"

int		chunk_sort(t_stack *a, t_stack *b);
int		count_chunk_size(t_stack *a);
int		is_in_chunk(int index, int min, int max);
int		still_in_a(t_stack *a, int min, int max);
void	loop_rotate(t_stack *a, int index_chunk, char letter);
void	loop_reverse_rotate(t_stack *a, int index_chunk, char letter);
int		push_chunk_to_b(t_stack *a, t_stack *b, int total_chk, int chk_size);
int		push_to_stacka_b(t_stack *a, t_stack *b, int min, int max);
int		find_closest_value_chunk(t_stack *a, int min, int max);

#endif
