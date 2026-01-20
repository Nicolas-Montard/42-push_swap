/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:15:16 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/19 12:05:17 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdarg.h>

int	print_param_type(char c, va_list va_ptr, int *char_print, int std)
{
	if (c == 'c')
		ft_putchar((char)va_arg(va_ptr, int), char_print, std);
	else if (c == 's')
		ft_putstr(va_arg(va_ptr, char *), char_print, std);
	else if (c == 'p')
		ft_put_memory(va_arg(va_ptr, void *), char_print, std);
	else if (c == 'd')
		ft_putnbr(va_arg(va_ptr, int), char_print, std);
	else if (c == 'i')
		ft_putnbr(va_arg(va_ptr, int), char_print, std);
	else if (c == 'u')
		ft_putunbr(va_arg(va_ptr, unsigned int), char_print, std);
	else if (c == 'x')
		ft_put_hex_nbr(va_arg(va_ptr, unsigned int), 1, char_print, std);
	else if (c == 'X')
		ft_put_hex_nbr(va_arg(va_ptr, unsigned int), 0, char_print, std);
	else if (c == '%')
		ft_putchar('%', char_print, std);
	else
	{
		ft_putchar('%', char_print, std);
		return (0);
	}
	return (1);
}

int	ft_printf(int std, const char *str, ...)
{
	va_list	va_ptr;
	int		i;
	int		char_print;

	char_print = 0;
	i = -1;
	if (!str)
		return (-1);
	va_start(va_ptr, str);
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			if (print_param_type(str[i + 1], va_ptr, &char_print, std))
				i++;
		}
		else
			ft_putchar(str[i], &char_print, std);
	}
	va_end(va_ptr);
	return (char_print);
}
/*
#include <stdio.h>

int	main(void)
{
	char var = 's';
	char *ptr = &var;
	char *str = "str";
	unsigned int us_int = 4294967295;
	int printf_return;
	int ft_printf_return;
	ft_printf_return = 0;
	printf_return = 0;
	str = 0;
	ptr = 0;
	// printf_return = printf("issprintf : 
	// dsds %p %i %s %d %u %x %X %%\n", ptr, 4, "test",
	// 	2147483647, us_int, us_int, us_int);
	// ft_printf_return = ft_printf("ft_printf : 
	// dsds %p %i %s %d %u %x %X %%\n", ptr, 4, "test",
	// 	2147483647, us_int, us_int, us_int);
	printf_return = printf("%p", 16);
	ft_printf_return = ft_printf("%p", 16);
	printf("\n");
	printf("printf return : %d\n", printf_return);
	printf("ft_printf return : %d\n", ft_printf_return);
}*/