/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:24:58 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/19 12:02:56 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void static	ft_setbase(char base[], int is_lc)
{
	int		i;
	char	letter;

	if (is_lc)
		letter = 'a';
	else
		letter = 'A';
	i = 0;
	while (i < 10)
	{
		base[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		base[i] = letter;
		letter++;
		i++;
	}
}

static void	ft_calculate(unsigned int nb, char base[], int *char_print, int std)
{
	if (nb >= 16)
	{
		ft_calculate(nb / 16, base, char_print, std);
		ft_calculate(nb % 16, base, char_print, std);
	}
	else
		ft_putchar(base[nb], char_print, std);
}

void	ft_put_hex_nbr(unsigned int n, int is_lc, int *char_print, int std)
{
	char	base[16];

	ft_setbase(base, is_lc);
	ft_calculate(n, base, char_print, std);
}
