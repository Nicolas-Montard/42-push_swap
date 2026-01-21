/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:12:20 by nmontard          #+#    #+#             */
/*   Updated: 2025/11/15 12:19:09 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

static int	calc_str_size(unsigned int nb, int sign)
{
	int	str_size;

	str_size = 0;
	if (sign == -1)
		str_size++;
	while (nb > 9)
	{
		nb /= 10;
		str_size++;
	}
	str_size++;
	return (str_size);
}

static void	fill_str(char *str, unsigned int nb, int sign, int str_size)
{
	str[str_size] = '\0';
	while (nb > 9)
	{
		str_size--;
		str[str_size] = (nb % 10) + 48;
		nb /= 10;
	}
	str_size--;
	str[str_size] = nb + 48;
	if (sign == -1)
	{
		str_size--;
		str[str_size] = '-';
	}
}

char	*ft_itoa(int n)
{
	int				sign;
	int				str_size;
	char			*result;
	unsigned int	nb;

	str_size = 1;
	sign = 1;
	if (n < 0)
	{
		sign *= -1;
		nb = -1 * n;
	}
	else
		nb = n;
	str_size = calc_str_size(nb, sign);
	result = malloc(sizeof(char) * (str_size + 1));
	if (!result)
		return (result);
	fill_str(result, nb, sign, str_size);
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	char *result;

	result = ft_itoa(652);
	printf("%s\n", result);
	printf("%c\n", result[0]);
	printf("%c\n", result[1]);
	printf("%c\n", result[2]);
	free(result);
	return (0);
}*/