/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:39:52 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/19 15:57:43 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <unistd.h>

void	ft_putunbr(unsigned int nb, int *char_print, int std)
{
	if (nb > 9)
	{
		ft_putunbr(nb / 10, char_print, std);
		ft_putunbr(nb % 10, char_print, std);
	}
	else
		ft_putchar(nb + 48, char_print, std);
}

void	ft_putstr(char *str, int *char_print, int std)
{
	int	i;

	if (!str)
	{
		write(std, "(null)", 6);
		*char_print += 6;
		return ;
	}
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], char_print, std);
		i++;
	}
}

void	ft_putnbr(int n, int *char_print, int std)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = n * -1;
		ft_putchar('-', char_print, std);
	}
	else
		nb = n;
	if (nb > 9)
	{
		ft_putnbr(nb / 10, char_print, std);
		ft_putnbr(nb % 10, char_print, std);
	}
	else
		ft_putchar(nb + 48, char_print, std);
}

void	ft_putchar(char c, int *char_print, int std)
{
	write(std, &c, 1);
	*char_print += 1;
}
