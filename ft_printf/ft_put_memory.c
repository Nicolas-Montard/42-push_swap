/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:35:56 by nmontard          #+#    #+#             */
/*   Updated: 2025/12/09 15:53:49 by nmontard         ###   ########.fr       */
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

static void	ft_calculate(unsigned long nb, char base[], int *char_print)
{
	if (nb >= 16)
	{
		ft_calculate(nb / 16, base, char_print);
		ft_calculate(nb % 16, base, char_print);
	}
	else
		ft_putchar(base[nb], char_print);
}

void	ft_put_memory(const void *addr, int *char_print)
{
	char	base[16];

	ft_setbase(base);
	if (!addr)
	{
		ft_putstr("(nil)", char_print);
		return ;
	}
	ft_putstr("0x", char_print);
	ft_calculate((unsigned long)addr, base, char_print);
}
