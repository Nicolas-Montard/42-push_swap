/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:13:59 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/19 11:13:52 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*newstr;
	unsigned int	s1_len;
	unsigned int	s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = ft_calloc((s1_len + s2_len + 2), sizeof(char));
	if (!newstr)
		return (newstr);
	ft_strlcat(newstr, s1, s1_len + 1);
	ft_strlcat(newstr, " ", s1_len + 2);
	ft_strlcat(newstr, s2, s1_len + s2_len + 2);
	return (newstr);
}
