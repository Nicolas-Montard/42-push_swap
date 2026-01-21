/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:36:46 by nmontard          #+#    #+#             */
/*   Updated: 2025/11/12 12:46:48 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	int				j;
	unsigned int	little_len;
	unsigned int	big_len;

	i = 0;
	big_len = ft_strlen(big);
	little_len = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		if (big[i] == little[j] && (i + little_len) <= len && (i
				+ little_len) <= big_len)
		{
			while (big[i + j] == little[j] && little[j] != '\0')
				j++;
			if (little[j] == '\0')
				return (&(((char *)big)[i]));
		}
		i++;
	}
	return (0);
}
