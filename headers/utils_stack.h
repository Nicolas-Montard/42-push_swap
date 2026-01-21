/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:19:01 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/21 14:23:12 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_STACK_H
# define UTILS_STACK_H

# include "stack.h"

int		create_both_stacks(t_stacks *stacks, char **numbers);

void	free_stacks(t_stacks **stacks);

#endif