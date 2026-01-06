/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:23:33 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/06 13:08:13 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTILS_H
# define LIST_UTILS_H

# include "stack.h"

t_node	*get_last_node(t_stack *stack);

t_node	*add_node(t_stack *stack, int value);

void	remove_node(t_stack *stack, t_node *node);

#endif