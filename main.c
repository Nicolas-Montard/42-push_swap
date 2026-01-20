/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:48:11 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/20 10:40:39 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/chunk_sort.h"
#include "headers/ft_printf.h"
#include "headers/libft.h"
#include "headers/list_utils.h"
#include "headers/parsing.h"
#include "headers/quick_sort.h"
#include "headers/selection_sort.h"
#include "headers/stack.h"
#include "headers/benchmark.h"
#include <stdlib.h>
#include <unistd.h>

t_stack	*create_stack(char **values)
{
	t_stack	*stack;
	int		value;
	int		i;

	i = 0;
	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->head = NULL;
	stack->size = 0;
	if (values == NULL)
		return (stack);
	while (values[i] != NULL)
	{
		value = atoi(values[i]);
		if (add_node(stack, value) == NULL)
		{
			delete_stack(&stack);
			return (NULL);
		}
		i++;
	}
	return (stack);
}

static int	create_both_stacks(t_stack **stackA, t_stack **stackB,
		char **numbers)
{
	*stackA = create_stack(numbers);
	if (*stackA == NULL)
	{
		return (0);
	}
	*stackB = create_stack(NULL);
	if (*stackB == NULL)
	{
		delete_stack(stackA);
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

int	main(int argc, char *argv[])
{
	t_stack	*stackA;
	t_stack	*stackB;
	int		flags[3];
	char	**numbers;
	int		error;

	error = 0;
	numbers = verif_input(argc, argv, flags, &error);
	// stacks = malloc(sizeof(t_stacks));
	// if (!stacks)
	// 	return (0);
	// stacks->bench = malloc(sizeof(t_bench));
	// if (!stacks->bench)
	// 	return (0);
	// end_at = 1;
	if (error == 1)
	{
		delete_numbers(&numbers);
		write(2, "Error\n", 6);
		return (1);
	}
	if (!create_both_stacks(&stackA, &stackB, numbers))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	delete_numbers(&numbers);
	if (stackA->size < 2)
	{
		// call function bench
		return (0);
	}
	if (flags[0] == 1)
		selection_sort(stackA, stackB);
	else if (flags[0] == 2)
		chunk_sort(stackA, stackB);
	else if (flags[0] == 3)
		quick_sort(stackA, stackB);
	// TODO add adaptative
	if (flags[1] == 1)
	{
		// TODO call bench function
	}
	selector = "Adaptive";
	algo = "O(n√n)";
	benchmark(selector, algo, stacks->bench);
	delete_stack(&stacks->a);
	delete_stack(&stacks->b);
	return (0);
}
