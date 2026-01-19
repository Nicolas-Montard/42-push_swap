/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:35:19 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/19 17:24:14 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include "headers/libft.h"
#include <stdlib.h>

static int	has_only_number(char **values)
{
	int	i;
	int	j;
	int	not_digit_counter;

	not_digit_counter = 0;
	j = 0;
	while (values[j] != NULL)
	{
		i = 0;
		while (values[j][i] != '\0')
		{
			if ((!ft_isdigit(values[j][i])) || (values[j][0] == '0'
					&& values[j][1] != '\0'))
			{
				if ((not_digit_counter >= 1 && values[j][0] == '-')
					|| (not_digit_counter >= 0 && values[j][0] != '-'))
				{
					return (0);
				}
				not_digit_counter++;
			}
			i++;
		}
		j++;
	}
	return (1);
}

static int	has_no_same_number(char **values)
{
	int	i;
	int	j;

	i = 0;
	while (values[i] != NULL)
	{
		j = 1;
		while (values[j + i] != NULL)
		{
			if (ft_strncmp(values[j + i], values[i], 12) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	verif_complexity_flag(char *str)
{
	if (ft_strncmp(str, "--simple", 9) == 0)
		return (1);
	if (ft_strncmp(str, "--medium", 9) == 0)
		return (2);
	if (ft_strncmp(str, "--complex", 10) == 0)
		return (3);
	if (ft_strncmp(str, "--adaptative", 13) == 0)
		return (4);
	return (0);
}

static int	verif_flag(char *argv[], int flags[2], int argc)
{
	int	i;

	i = 1;
	if (argc < 2)
		return (1);
	// first index represent complexity level, 0 is no parameter,
	// 1 is simple, 2 is medium, 3 is complex, 4 is adaptative
	flags[0] = 0;
	// second index is for presence of bench flag, 0 no flag, 1 flag exist
	flags[1] = 0;
	flags[2] = 0;
	while (argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (flags[1] == 0 && ft_strncmp("--bench", argv[i], 8) == 0)
			flags[1] = 1;
		else if (flags[0] == 0 && verif_complexity_flag(argv[i]))
		{
			flags[0] = verif_complexity_flag(argv[i]);
			flags[2] = verif_complexity_flag(argv[i]);
		}
		else
			return (0);
		i++;
	}
	return (1);
}

static char	**normalize_numbers(int argc, char *argv[])
{
	int		i;
	char	*numbers;
	char	*temp;
	char	**result;

	i = 1;
	if (argc == 0)
	{
		result = malloc(sizeof(char *) * 1);
		result[0] = NULL;
		return (result);
	}
	numbers = ft_strdup(argv[0]);
	if (!numbers)
		return (NULL);
	while (i < argc)
	{
		temp = numbers;
		numbers = ft_strjoin(numbers, argv[i]);
		free(temp);
		if (!numbers)
			return (NULL);
		i++;
	}
	result = ft_split(numbers, ' ');
	free(numbers);
	return (result);
}

static int	numbers_are_int(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i] != NULL)
	{
		if (numbers[i][0] == '-')
		{
			if (ft_strlen(numbers[i]) > 11)
				return (0);
			else if (ft_strlen(numbers[i]) == 11)
			{
				if (ft_strncmp(numbers[i], "-2147483648", 12) > 0)
					return (0);
			}
		}
		else
		{
			if (ft_strlen(numbers[i]) > 10)
				return (0);
			else if (ft_strlen(numbers[i]) == 10)
			{
				if (ft_strncmp(numbers[i], "2147483647", 11) > 0)
					return (0);
			}
		}
		i++;
	}
	return (1);
}

char	**return_error(char **numbers, int *error)
{
	*error = 1;
	return (numbers);
}

char	**verif_input(int argc, char *argv[], int flags[2], int *error)
{
	char	**numbers;
	int		nb_flag;

	numbers = NULL;
	nb_flag = 0;
	ft_printf("1\n");
	if (!verif_flag(argv, flags, argc))
		return_error(numbers, error);
	ft_printf("2\n");
	if (flags[0] > 0)
		nb_flag++;
	if (flags[1] > 0)
		nb_flag++;
	numbers = normalize_numbers(argc - nb_flag - 1, &(argv[nb_flag + 1]));
	ft_printf("3\n");
	if (numbers == NULL)
		return_error(numbers, error);
	ft_printf("4\n");
	if (!has_only_number(numbers))
		return_error(numbers, error);
	ft_printf("5\n");
	if (!has_no_same_number(numbers))
		return_error(numbers, error);
	ft_printf("6\n");
	if (!numbers_are_int(numbers))
		return_error(numbers, error);
	ft_printf("7\n");
	return (numbers);
}
