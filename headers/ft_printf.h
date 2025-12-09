/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:49:26 by nmontard          #+#    #+#             */
/*   Updated: 2025/12/09 15:52:05 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

void	ft_putunbr(unsigned int nb, int *char_print);
void	ft_putstr(char *str, int *char_print);
void	ft_putnbr(int n, int *char_print);
void	ft_putchar(char c, int *char_print);
void	ft_put_hex_nbr(unsigned int n, int is_lc, int *char_print);
void	ft_put_memory(const void *addr, int *char_print);
int		ft_printf(const char *str, ...);
#endif