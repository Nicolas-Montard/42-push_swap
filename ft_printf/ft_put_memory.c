/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:35:56 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/19 16:22:18 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void static	ft_setbase(char base[])
{
	int		i;
	char	letter;

	letter = 'a';
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

static void	ft_calculate(unsigned long nb, char base[], int *char_print, int st)
{
	if (nb >= 16)
	{
		ft_calculate(nb / 16, base, char_print, st);
		ft_calculate(nb % 16, base, char_print, st);
	}
	else
		ft_putchar(base[nb], char_print, st);
}

void	ft_put_memory(const void *addr, int *char_print, int std)
{
	char	base[16];

	ft_setbase(base);
	if (!addr)
	{
		ft_putstr("(nil)", char_print, std);
		return ;
	}
	ft_putstr("0x", char_print, std);
	ft_calculate((unsigned long)addr, base, char_print, std);
}
