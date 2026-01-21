/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:16:26 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/21 14:47:28 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include "list_utils.h"
#include <stdlib.h>

static t_stack	*create_stack(char **values)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->head = NULL;
	stack->size = 0;
	if (values == NULL)
		return (stack);
	if (values[i] == NULL)
		return (stack);
	while (values[i + 1] != NULL)
		i++;
	while (i >= 0)
	{
		if (add_node(stack, atoi(values[i])) == NULL)
		{
			delete_stack(&stack);
			return (NULL);
		}
		i--;
	}
	return (stack);
}

int	create_both_stacks(t_stacks *stacks, char **numbers)
{
	stacks->a = create_stack(numbers);
	if (stacks->a == NULL)
	{
		return (0);
	}
	stacks->b = create_stack(NULL);
	if (stacks->b == NULL)
	{
		delete_stack(&(stacks->a));
		return (0);
	}
	return (1);
}

void	free_stacks(t_stacks **stacks)
{
	if ((*stacks)->a != NULL)
		delete_stack(&((*stacks)->a));
	if ((*stacks)->b != NULL)
		delete_stack(&((*stacks)->b));
	if ((*stacks)->bench != NULL)
		free((*stacks)->bench);
	free(*stacks);
	*stacks = NULL;
}
