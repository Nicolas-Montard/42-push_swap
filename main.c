/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:48:11 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/21 16:59:11 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/benchmark.h"
#include "headers/chunk_sort.h"
#include "headers/disorder_metric.h"
#include "headers/ft_printf.h"
#include "headers/list_utils.h"
#include "headers/parsing.h"
#include "headers/quick_sort.h"
#include "headers/selection_sort.h"
#include "headers/stack.h"
#include "headers/utils_stack.h"
#include <stdlib.h>

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

static int	end_main(char ***numbers, t_stacks **stacks, int return_value)
{
	if (*numbers != NULL)
		delete_numbers(numbers);
	free_stacks(stacks);
	if (return_value == 1)
		ft_printf(2, "Error\n");
	return (return_value);
}

static int	select_algo(t_stacks *stacks, int flags[2])
{
	int	error;

	error = 1;
	if (stacks->a->size < 2)
	{
		if (flags[1] == 1)
			benchmark(stacks->bench);
		free_stacks(&stacks);
		return (0);
	}
	if (flags[0] == 1)
		error = selection_sort(stacks);
	else if (flags[0] == 2)
		error = chunk_sort(stacks);
	else if (flags[0] == 3)
		error = quick_sort(stacks);
	else
		error = adaptative(stacks);
	if (error == 0)
		return (0);
	if (flags[1] == 1)
		benchmark(stacks->bench);
	return (1);
}

t_stacks	*inititalize_stacks(void)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (stacks == NULL)
		return (NULL);
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->bench = NULL;
	return (stacks);
}

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;
	int			flags[2];
	char		**numbers;
	int			error;

	error = 0;
	numbers = verif_input(argc, argv, flags, &error);
	stacks = inititalize_stacks();
	if (stacks == NULL)
		return (end_main(&numbers, &stacks, 1));
	if (error == 1)
		return (end_main(&numbers, &stacks, 1));
	if (!create_both_stacks(stacks, numbers))
		return (end_main(&numbers, &stacks, 1));
	stacks->bench = malloc(sizeof(t_bench));
	if (!stacks->bench)
		return (end_main(&numbers, &stacks, 1));
	stacks->bench->algo_type = flags[0];
	delete_numbers(&numbers);
	stacks->bench->disorder_metric = compute_disorder(stacks->a);
	select_algo(stacks, flags);
	free_stacks(&stacks);
	return (0);
}
