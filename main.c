/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:48:11 by nmontard          #+#    #+#             */
/*   Updated: 2025/12/20 14:22:49 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/list_utils.h"
#include "headers/stack.h"
#include "headers/utils.h"
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
				|| (values[start][i] == '0' && i == 0))
			{
				return (0);
			}
			i++;
		}
		start++;
	}
	return (1);
}

t_stack	*create_stack(char *values[], int start, int argc)
{
	t_stack	*stack;
	int		*value;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	while (start < argc)
	{
		value = malloc(sizeof(int));
		if (value == NULL)
		{
			// TODO create and use clean stack here
			return (NULL);
		}
		*value = atoi(values[start]);
		if (add_node_last(stack, value) == NULL)
		{
			// TODO create and use clean stack here
			return (NULL);
		}
		start++;
	}
	return (stack);
}

t_stack	*create_empty_stack(int start, int argc)
{
	t_stack	*stack;
	int		*value;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	while (start < argc)
	{
		if (add_node_last(stack, NULL) == NULL)
		{
			// TODO create and use clean stack here
			return (NULL);
		}
		start++;
	}
	return (stack);
}

int	main(int argc, char *argv[])
{
	int		nb_start_at;
	t_stack	*stackA;
	t_stack	*stackB;

	nb_start_at = 1;
	// TODO set nb_start_at values base on arg
	// TODO send error message
	if (!has_only_number(argv, 1, argc))
		return (0);
	stackA = create_stack(argv, nb_start_at, argc);
	stackB = create_empty_stack(nb_start_at, argc);
}
