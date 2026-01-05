/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:25:56 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/05 12:30:14 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct node
{
	int			*value;
	struct node	*previous;
	struct node	*next;
}				t_node;

typedef struct stack
{
	struct node	*head;
	int			size;
}				t_stack;

void			sa(t_stack *stack);

void			sb(t_stack *stack);

void			ss(t_stack *a, t_stack *b);

void			pa(t_stack *a, t_stack *b);

void			pb(t_stack *b, t_stack *a);

void			ra(t_stack *a);

void			rb(t_stack *b);

void			rr(t_stack *a, t_stack *b);

void			rra(t_stack *a);

void			rrb(t_stack *b);

void			rrr(t_stack *a, t_stack *b);

#endif
