/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:46:07 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/20 14:50:44 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"
#include <stdlib.h>

static char	**normalize_if_size_zero(void)
{
	char	**result;

	result = malloc(sizeof(char *) * 1);
	if (result != NULL)
		result[0] = NULL;
	return (result);
}

char	**normalize_numbers(int argc, char *argv[])
{
	int i;
	char *numbers;
	char *temp;
	char **result;

	i = 1;
	if (argc == 0)
		return (normalize_if_size_zero());
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