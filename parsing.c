/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:35:19 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/16 16:51:30 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	has_only_number(char **values)
{
	int	i;
	int	j;

	j = 0;
	while (values[i] != NULL)
	{
		i = 0;
		while (values[j][i] != '\0')
		{
			if (values[j][i] < '0' || values[j][i] > '9' || (values[j][0] == '0'
					&& values[j][1] != '\0'))
			{
				return (0);
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
			if (ft_strncmp(values[j + i], values[i], ft_strlen(values[i])) != 0)
				return (0);
			j++;
		}
	}
	return (1);
}

static int	verif_complexity_flag(char *str)
{
	if (ft_strncmp(str, "--simple", 9))
		return (1);
	if (ft_strncmp(str, "--medium", 9))
		return (2);
	if (ft_strncmp(str, "--complex", 10))
		return (3);
	if (ft_strncmp(str, "--adaptative", 13))
		return (4);
	return (0);
}

static int	verif_flag(char *argv[], int flags[2])
{
	int	i;

	i = 1;
	// first index represent complexity level, 0 is no parameter,
	// 1 is simple, 2 is medium, 3 is complex, 4 is adaptative
	flags[0] = 0;
	// second index is for presence of bench flag, 0 no flag, 1 flag exist
	flags[1] = 0;
	while (!ft_isdigit(argv[i][0]))
	{
		if (flags[1] == 0 && ft_strncmp("--bench", argv[i], 8) == 0)
			flags[1] = 1;
		else if (flags[0] == 0 && verif_complexity_flag(argv[i]))
			flags[0] = verif_complexity_flag(argv[i]);
		else
			return (0);
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
	char **numbers;
	int nb_flag;

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
