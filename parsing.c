/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:35:19 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/22 12:03:04 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"
#include "headers/parsing.h"
#include <stdlib.h>

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

// first index of flags represent complexity level, 0 is no parameter,
// 1 is simple, 2 is medium, 3 is complex, 4 is adaptative
// second index of flags is for presence of bench flag, 0 no flag, 1 flag exist
static int	verif_flag(char *argv[], int flags[2], int argc)
{
	int	i;

	i = 1;
	flags[0] = 0;
	flags[1] = 0;
	if (argc < 2)
		return (1);
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (flags[1] == 0 && ft_strncmp("--bench", argv[i], 8) == 0)
			flags[1] = 1;
		else if (flags[0] == 0 && verif_complexity_flag(argv[i]))
			flags[0] = verif_complexity_flag(argv[i]);
		else
			return (0);
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
	if (!verif_flag(argv, flags, argc))
		return (return_error(numbers, error));
	if (flags[0] > 0)
		nb_flag++;
	if (flags[1] > 0)
		nb_flag++;
	numbers = normalize_numbers(argc - nb_flag - 1, &(argv[nb_flag + 1]));
	if (numbers == NULL)
		return (return_error(numbers, error));
	if (!has_only_number(numbers))
		return (return_error(numbers, error));
	if (!has_no_same_number(numbers))
		return (return_error(numbers, error));
	if (!numbers_are_int(numbers))
		return (return_error(numbers, error));
	return (numbers);
}
