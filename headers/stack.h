/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:25:56 by nmontard          #+#    #+#             */
/*   Updated: 2025/12/09 14:42:48 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct stack
{
	int	top;
	int	size;
	int	*array;
}		t_stack;

void	swap(t_stack *stack);

void	ss(t_stack *a, t_stack *b);

void	swap(t_stack *stack);

void	ss(t_stack *a, t_stack *b);

#endif
