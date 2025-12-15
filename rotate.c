/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:35:03 by aslimani          #+#    #+#             */
/*   Updated: 2025/12/15 16:55:17 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"

void	ra(t_stack *a)
{
    int	last;
    int	i;

	if (a->size <= 1)
		return;

	last = a->array[a->top];
	i = a->top;
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = last;
}
void	ra(t_stack *b)
{
    int	last;
    int	i;

	if (b->size <= 1)
		return;

	last = b->array[b->top];
	i = b->top;
	while (i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = last;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

int	main(void)
{
	t_stack *stack1;
	int		*array1;

	stack1 = malloc(sizeof(t_stack));
	array1 = malloc(sizeof(int) * 6);
	stack1->array = array1;
	stack1->top = 5;
	stack1->size = 6;
	stack1->array[0] = 7;
	stack1->array[1] = 8;
	stack1->array[2] = 9;
	stack1->array[3] = 10;
	stack1->array[4] = 11;
	stack1->array[5] = 12;
	__builtin_printf("%d\n", stack1->array[0]);
	__builtin_printf("%d\n", stack1->array[1]);
	__builtin_printf("%d\n", stack1->array[2]);
	__builtin_printf("%d\n", stack1->array[3]);
	__builtin_printf("%d\n", stack1->array[4]);
	__builtin_printf("%d\n", stack1->array[5]);
	ra(stack1);
	ra(stack1);
	__builtin_printf("%d\n", stack1->array[0]);
	__builtin_printf("%d\n", stack1->array[1]);
	__builtin_printf("%d\n", stack1->array[2]);
	__builtin_printf("%d\n", stack1->array[3]);
	__builtin_printf("%d\n", stack1->array[4]);
	__builtin_printf("%d\n", stack1->array[5]);
}