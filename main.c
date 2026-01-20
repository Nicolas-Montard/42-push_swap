/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:48:11 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/20 14:04:52 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/benchmark.h"
#include "headers/chunk_sort.h"
#include "headers/disorder_metric.h"
#include "headers/ft_printf.h"
#include "headers/libft.h"
#include "headers/list_utils.h"
#include "headers/parsing.h"
#include "headers/quick_sort.h"
#include "headers/selection_sort.h"
#include "headers/stack.h"
#include <stdlib.h>
#include <unistd.h>

t_stack	*create_stack(char **values)
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

static int	create_both_stacks(t_stacks *stacks, char **numbers)
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

static void	delete_numbers(char ***numbers)
{
	int	i;

	i = 0;
	if (*numbers == NULL)
		return ;
	while ((*numbers)[i] != NULL)
	{
		free((*numbers)[i]);
		i++;
	}
	free(*numbers);
	*numbers = NULL;
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

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;
	int			flags[3];
	char		**numbers;
	int			error;

	error = 0;
	numbers = verif_input(argc, argv, flags, &error);
	stacks = malloc(sizeof(t_stacks));
	if (stacks == NULL)
		return (1);
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->bench = NULL;
	if (!stacks)
		return (1);
	if (error == 1)
	{
		delete_numbers(&numbers);
		free_stacks(&stacks);
		ft_printf(2, "Error\n");
		return (1);
	}
	if (!create_both_stacks(stacks, numbers))
	{
		delete_numbers(&numbers);
		free_stacks(&stacks);
		ft_printf(2, "Error\n");
		return (1);
	}
	stacks->bench = malloc(sizeof(t_bench));
	if (!stacks->bench)
		return (1);
	stacks->bench->algo_type = flags[0];
	delete_numbers(&numbers);
	stacks->bench->disorder_metric = compute_disorder(stacks->a);
	if (stacks->a->size < 2)
	{
		if (flags[1] == 1)
			benchmark(stacks->bench);
		free_stacks(&stacks);
		return (0);
	}
	if (flags[0] == 1)
		selection_sort(stacks);
	else if (flags[0] == 2)
		chunk_sort(stacks);
	else if (flags[0] == 3)
		quick_sort(stacks);
	else
		adaptative(stacks);
	if (flags[1] == 1)
		benchmark(stacks->bench);
	free_stacks(&stacks);
	return (0);
}
