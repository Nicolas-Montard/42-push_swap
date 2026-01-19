/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:49:26 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/19 12:07:01 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

void	ft_putunbr(unsigned int nb, int *char_print, int std);
void	ft_putstr(char *str, int *char_print, int std);
void	ft_putnbr(int n, int *char_print, int std);
void	ft_putchar(char c, int *char_print, int std);
void	ft_put_hex_nbr(unsigned int n, int is_lc, int *char_print, int std);
void	ft_put_memory(const void *addr, int *char_print, int std);
int		ft_printf(int std, const char *str, ...);
#endif