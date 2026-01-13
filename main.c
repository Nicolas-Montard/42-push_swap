/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:48:11 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/13 16:51:36 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/list_utils.h"
#include "headers/stack.h"
#include "headers/utils.h"
#include "quick_sort.h"
#include "headers/medium.h"
#include <stdlib.h>
#include <stdio.h>

int	has_only_number(char *values[], int start, int argc)
{
	int	i;

	while (start < argc)
	{
		i = 0;
		while (values[start][i] != '\0')
		{
			if (values[start][i] < '0' || values[start][i] > '9'
				|| (values[start][i] == '0' && i+1 == 0 && i == 0))
			{
				return (0);
			}
			i++;
		}
		start++;
	}
	return (1);
}

t_stack	*create_stack(char *values[], int start, int end)
{
	t_stack	*stack;
	int		value;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->head = NULL;
	stack->size = 0;
	while (start >= end)
	{
		value = atoi(values[start]);
		if (add_node(stack, value) == NULL)
		{
			// TODO create and use delete stack here
			return (NULL);
		}
		start--;
	}
	return (stack);
}

int	main(int argc, char *argv[])
{
	int		end_at;
	t_stack	*stackA;
	t_stack	*stackB;
	t_node	*start_node;
	t_node	*actual_node;

	end_at = 1;
	// TODO set end_at values base on arg
	// TODO send error message
	// TODO be able to take string of arg to sort
	if (!has_only_number(argv, 1, argc))
		return (0);
	stackA = create_stack(argv, argc - 1, end_at);
	if (stackA == NULL)
	{
		// TODO free the stack
		// TODO send error message
		return (0);
	}
	stackB = create_stack(NULL, 0, 1);
	if (stackB == NULL)
	{
		// TODO free both stack
		// TODO send error message
		return (0);
	}
	selection_sort(stackA, stackB);
	//medium_sort(stackA, stackB);
	//quick_sort(stackA, stackB);
	start_node = stackA->head;
	actual_node = start_node->next;
	//__builtin_printf("%d\n", start_node->value);
	while (actual_node != start_node)
	{
		//__builtin_printf("%d\n", actual_node->value);
		actual_node = actual_node->next;
	}
}
