/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:48:11 by nmontard          #+#    #+#             */
/*   Updated: 2025/12/18 16:08:52 by nmontard         ###   ########.fr       */
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

t_stack	*create_stacks(int *values[], int start, int argc)
{
	t_stack	*stackA;
	t_stack *stackB;
	int		value;
	int		pt_value;

	stackB = malloc(sizeof(t_stack));
	if (stackB == NULL)
		return (NULL);
	stackA = malloc(sizeof(t_stack));
	if (stackA == NULL)
	{
		free(stackB);
		return (NULL);
	}
	while (values[start] < argc + start - 1)
	{
		if (add_node_last(stack, ft_atoi(values[start])) == NULL)
		{
			// TODO create and use clean stack here
			return (0);
		}
		start++;
	}
}

int	main(int argc, char *argv[])
{
	// TODO set start values base on arg
	// TODO send error message
	if (!has_only_number(argv, 1, argc))
		return (0);
	create_stack(argv, 1, argc);
}
