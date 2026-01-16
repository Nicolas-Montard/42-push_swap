/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:48:11 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/16 16:51:06 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/chunk_sort.h"
#include "headers/libft.h"
#include "headers/list_utils.h"
#include "headers/quick_sort.h"
#include "headers/selection_sort.h"
#include "headers/stack.h"
#include <stdio.h>
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

char	**normalize_numbers(int argc, char *argv[])
{
	int		i;
	char	*numbers;
	char	*temp;
	char	**result;

	i = 1;
	numbers = ft_strdup(argv[0]);
	if (!numbers)
		return (NULL);
	while (i < argc)
	{
		temp = numbers;
		numbers = ft_strjoin(argv[i], argv[i + 1]);
		free(temp);
		if (!numbers)
			return (NULL);
	}
	result = ft_split(numbers, ' ');
	free(numbers);
	return (result);
}

char	**verif_input(int argc, char *argv[], int flags[2])
{
	char	**numbers;
	int		nb_flag;

	nb_flag = 0;
	// need to verif return value
	if (argc < 3)
		return (NULL);
	if (!verif_flag(argv, flags))
		return (NULL);
	if (flags[0] > 0)
		nb_flag++;
	if (flags[1] > 0)
		nb_flag++;
	// need to verif what need to be returned
	if (argc < 3 + nb_flag)
		return (NULL);
	numbers = normalize_numbers(argc - nb_flag - 1, &(argv[nb_flag + 1]));
	if (numbers == NULL)
		return (NULL);
	if (!has_only_number(numbers))
		return (NULL);
	if (!has_no_same_number(numbers))
		return (NULL);
	return (numbers);
}

int	main(int argc, char *argv[])
{
	t_stack	*stackA;
	t_stack	*stackB;
	int		flags[2];
	char	**numbers;

	numbers = verif_input(argc, argv, flags);
	if (numbers == NULL)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!create_both_stacks(stackA, stackB, numbers))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if(flags[0] == 1)
		selection_sort(stackA, stackB);
	else if (flags[0] == 2)
		chunk_sort(stackA, stackB);
	else if (flags[0] == 3)
		quick_sort(stackA, stackB);
	//
	delete_stack(&stackA);
	delete_stack(&stackB);
	return (0);
}
