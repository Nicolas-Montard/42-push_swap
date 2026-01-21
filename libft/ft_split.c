/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:22:14 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/16 12:34:06 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count_word(char const *s, char c)
{
	int	is_word;
	int	nb_word;

	is_word = 0;
	nb_word = 0;
	while (*s != '\0')
	{
		if (is_word == 0 && *s != c)
		{
			nb_word++;
			is_word = 1;
		}
		if (*s == c)
			is_word = 0;
		s++;
	}
	return (nb_word);
}

static unsigned int	ft_str_len_tochar(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char	**ft_clean_words(int i, char **result)
{
	while (i != -1)
	{
		free(result[i]);
		i--;
	}
	free(result);
	return (0);
}

static char	**ft_create_words(char const *s, char c, int nb_word, char **result)
{
	int	i;
	int	len_to_new_word;

	i = 0;
	while (i < nb_word)
	{
		while (*s == c)
			s++;
		len_to_new_word = ft_str_len_tochar(s, c);
		result[i] = ft_substr(s, 0, len_to_new_word);
		if (!result[i])
			return (ft_clean_words(i, result));
		s += len_to_new_word;
		while (*s == c)
			s++;
		i++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		nb_word;
	char	**result;

	nb_word = ft_count_word(s, c);
	if (!s)
		return (0);
	result = malloc(sizeof(char *) * (nb_word + 1));
	if (!result)
		return (result);
	if (!ft_create_words(s, c, nb_word, result))
		result = 0;
	if (result)
		result[nb_word] = 0;
	return (result);
}
