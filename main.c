/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:48:11 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/14 16:52:12 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/chunk_sort.h"
#include "headers/list_utils.h"
#include "headers/quick_sort.h"
#include "headers/selection_sort.h"
#include "headers/stack.h"
#include "headers/utils.h"
#include <stdio.h>
#include <stdlib.h>

int	has_only_number(char *values[], int start, int argc)
{
	int	i;

	while (start < argc)
	{
		i = 0;
		while (values[start][i] != '\0')
		{
			if (values[start][i] < '0' || values[start][i] > '9'
				|| (values[start][i] == '0' && i + 1 == 0 && i == 0))
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
			delete_stack(&stack);
			return (NULL);
		}
		start--;
	}
	return (stack);
}

static int	create_both_stacks(int argc, char *argv[], t_stack **stackA,
		t_stack **stackB, int nb_start_at)
{
	stackA = create_stack(argv, argc - 1, nb_start_at);
	if (stackA == NULL)
	{
		printf("Error");
		return (0);
	}
	stackB = create_stack(NULL, 0, 1);
	if (stackB == NULL)
	{
		delete_stack(stackA);
		printf("Error");
		return (0);
	}
	return (1);
}

int	*verif_flag(int argc, char *argv[])
{
	int	flags[2];

	// first index represent complexity level, 0 is no parameter, 
	// 1 is simple, 2 is medium, 3 is complex, 4 is adaptative
	flags[0] = 0;
	flags[1] = 0;
}

int	main(int argc, char *argv[])
{
	int		nb_start_at;
	t_stack	*stackA;
	t_stack	*stackB;

	nb_start_at = 1;
	// TODO set end_at values base on arg
	// TODO be able to take string of arg to sort
	if (!has_only_number(argv, nb_start_at, argc))
	{
		printf("Error");
		return (1);
	}
	if (!create_both_stacks(argc, argv, &stackA, &stackB, nb_start_at))
	{
		printf("Error");
		return (1);
	}
	// selection_sort(stackA, stackB);
	// chunk_sort(stackA, stackB);
	quick_sort(stackA, stackB);
	delete_stack(&stackA);
	delete_stack(&stackB);
	return (0);
}
