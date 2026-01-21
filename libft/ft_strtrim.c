/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:44:08 by nmontard          #+#    #+#             */
/*   Updated: 2025/11/14 09:09:56 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count_set_start(char const *s1, char const *set)
{
	int				i;
	unsigned int	j;
	int				set_found;

	j = 0;
	set_found = 1;
	while (s1[j] != '\0' && set_found)
	{
		set_found = 0;
		i = 0;
		while (set[i] != '\0')
		{
			if (s1[j] == set[i])
			{
				set_found = 1;
				break ;
			}
			i++;
		}
		if (set_found)
			j++;
	}
	return (j);
}

static unsigned int	ft_count_set_end(char const *s1, char const *set)
{
	int				i;
	unsigned int	j;
	int				set_found;
	unsigned int	s1_len;

	s1_len = ft_strlen(s1);
	j = s1_len;
	set_found = 1;
	while (j > 0 && set_found)
	{
		set_found = 0;
		i = 0;
		while (set[i] != '\0')
		{
			if (s1[j - 1] == set[i])
			{
				set_found = 1;
				break ;
			}
			i++;
		}
		if (set_found)
			j--;
	}
	return (s1_len - j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start_set_char;

	if (!s1)
		return (0);
	start_set_char = ft_count_set_start(s1, set);
	return (ft_substr(s1, start_set_char, (ft_strlen(s1) - (ft_count_set_end(s1,
						set) + start_set_char))));
}
/*
int	main(void)
{
	printf("%s" ,ft_strtrim("+*+*++test+-++++**+", "+*"));
	return (0);
}*/
