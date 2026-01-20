/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:25:56 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/19 17:41:53 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "benchmark.h"

typedef struct node
{
	int			value;
	int			index;
	struct node	*previous;
	struct node	*next;
}				t_node;

typedef struct stack
{
	struct node	*head;
	int			size;
}				t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	t_bench	*bench;
}				t_stacks;

void			sa(t_stacks *stack);

void			sb(t_stacks *stack);

void			ss(t_stacks *stack);

void			ra(t_stacks *stack);

void			rb(t_stacks *stack);

void			rr(t_stacks *stack);

void			rra(t_stacks *stack);

void			rrb(t_stacks *stack);

void			rrr(t_stacks *stack);

int				pa(t_stacks *stack);

int				pb(t_stacks *stack);

#endif
