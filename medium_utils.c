/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:57:26 by aslimani          #+#    #+#             */
/*   Updated: 2026/01/13 16:59:54 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include <stdlib.h>
#include "headers/medium.h"

//calculate the square root of n elements

int	count_chunk_size(t_stack *a)
{
	int		chunk_size;
	int		number;

	number = 1;
	chunk_size = 0;
	while (number * number < a->size)
	{
		number++;
		chunk_size++;
	}
	return (chunk_size);
}

//checks if a value belongs to the chunk

int	is_in_chunk(int index, int min, int max)
{
	if (index >= min && index <= max)
		return (1);
	return (0);
}
//check if there are any chunk values ​​left in A

int	still_in_a(t_stack *a, int min, int max)
{
	t_node	*i;
	int		index_i;

	i = a->head;
	index_i = 0;
	while (index_i < a->size)
	{
		if (is_in_chunk(i->index, min, max))
			return (1);
		i = i->next;
		index_i++;
	}
	return (0);
}

void	loop_rotate(t_stack *stack, int index, char letter)
{
	int	r;

	r = 0;
	if (letter == 'a')
	{
		while (r < index)
		{
			ra(stack);
			r++;
		}
	}
	else
	{
		while (r < index)
		{
			rb(stack);
			r++;
		}
	}
}

void	loop_reverse_rotate(t_stack *stack, int index, char letter)
{
	int	rev;

	rev = 0;
	if (letter == 'a')
	{
		while (rev < stack->size - index)
		{
			rra(stack);
			rev++;
		}
	}
	else
	{
		while (rev < stack->size - index)
		{
			rrb(stack);
			rev++;
		}
	}
}
