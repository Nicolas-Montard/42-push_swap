/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:14:50 by nmontard          #+#    #+#             */
/*   Updated: 2025/11/17 14:09:40 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s, size_t n, unsigned int limit)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (limit + 1));
	if (!dest)
		return (dest);
	while (s[i] != '\0' && i < n)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	limit;
	char			*substr;

	i = 0;
	limit = 0;
	while (i < start && s[i] != '\0')
		i++;
	while (s[i + limit] != '\0' && limit < len)
		limit++;
	substr = ft_strndup(&(s[i]), len, limit);
	return (substr);
}

/*
int	main(void)
{
	char	*str;

	str = "test c'est une phrase ++++";
	printf("%s",ft_substr(str, 5, 10));
}
*/