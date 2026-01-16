/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:05:43 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/15 15:13:12 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*array;
	unsigned int	i;
	unsigned int	t_size;

	i = 0;
	if (nmemb <= 0 || size <= 0)
		return (malloc(0));
	if (size && nmemb > UINT_MAX / size)
		return (0);
	t_size = nmemb * size;
	array = malloc(nmemb * size);
	if (!array)
		return (array);
	while (i < t_size)
	{
		((char *)array)[i] = 0;
		i++;
	}
	return (array);
}
