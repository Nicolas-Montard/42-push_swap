/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:39:52 by nmontard          #+#    #+#             */
/*   Updated: 2025/12/09 15:52:21 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <unistd.h>

void	ft_putunbr(unsigned int nb, int *char_print)
{
	if (nb > 9)
	{
		ft_putunbr(nb / 10, char_print);
		ft_putunbr(nb % 10, char_print);
	}
	else
		ft_putchar(nb + 48, char_print);
}

void	ft_putstr(char *str, int *char_print)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		*char_print += 6;
		return ;
	}
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], char_print);
		i++;
	}
}

void	ft_putnbr(int n, int *char_print)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = n * -1;
		ft_putchar('-', char_print);
	}
	else
		nb = n;
	if (nb > 9)
	{
		ft_putnbr(nb / 10, char_print);
		ft_putnbr(nb % 10, char_print);
	}
	else
		ft_putchar(nb + 48, char_print);
}

void	ft_putchar(char c, int *char_print)
{
	write(1, &c, 1);
	*char_print += 1;
}
