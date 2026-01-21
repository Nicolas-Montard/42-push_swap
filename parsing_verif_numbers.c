/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_verif_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:38:11 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/21 16:55:32 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"
#include <stdlib.h>

int	has_only_number(char **values)
{
	int	i;
	int	j;
	int	not_digit_counter;

	j = 0;
	while (values[j] != NULL)
	{
		i = 0;
		not_digit_counter = 0;
		while (values[j][i] != '\0')
		{
			if ((!ft_isdigit(values[j][i])) || (values[j][0] == '0'
					&& values[j][1] != '\0'))
			{
				if ((not_digit_counter >= 1 && values[j][0] == '-')
					|| (not_digit_counter >= 0 && values[j][0] != '-'))
					return (0);
				not_digit_counter++;
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	has_no_same_number(char **values)
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

int	number_is_int_positive(char *number)
{
	if (ft_strlen(number) > 10)
		return (0);
	else if (ft_strlen(number) == 10)
	{
		if (ft_strncmp(number, "2147483647", 11) > 0)
			return (0);
	}
	return (1);
}

int	number_is_int_negative(char *number)
{
	if (ft_strlen(number) > 11)
		return (0);
	else if (ft_strlen(number) == 11)
	{
		if (ft_strncmp(number, "-2147483648", 12) > 0)
			return (0);
	}
	return (1);
}

int	numbers_are_int(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i] != NULL)
	{
		if (numbers[i][0] == '-')
		{
			if (!number_is_int_negative(numbers[i]))
				return (0);
		}
		else if (!number_is_int_positive(numbers[i]))
			return (0);
		i++;
	}
	return (1);
}
