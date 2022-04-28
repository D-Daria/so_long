/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:26:19 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/01/21 01:12:54 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_str_free(char **split_string, size_t	w)
{
	while (w >= 0)
	{
		free(split_string[w]);
		split_string[w] = NULL;
		w--;
	}
	free(split_string);
	split_string = NULL;
}

static size_t	ft_w_count(char const *str, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0' && str[i] != c)
			counter++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (counter);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	w;

	w = 0;
	while (*s != '\0' && *s != c)
	{
		w++;
		s++;
	}
	return (w);
}

static char	**ft_fill_str(char const *s, char c,
							size_t	count_words, char **split_string)
{
	size_t	i;

	i = 0;
	while (*s != '\0' && count_words > i)
	{
		while (*s != '\0' && *s == c)
			s++;
		split_string[i] = ft_substr(s, 0, ft_word_len(s, c));
		if (split_string[i] == NULL)
		{
			ft_str_free(split_string, i);
			return (NULL);
		}
		s = s + ft_word_len(s, c);
		i++;
	}
	split_string[i] = NULL;
	return (split_string);
}

char	**ft_split(const char *s, char c)
{
	size_t	count_words;
	char	**split_string;

	if (s == NULL)
		return (NULL);
	count_words = ft_w_count(s, c);
	split_string = (char **)malloc(sizeof(char *) * (count_words + 1));
	if (split_string == NULL)
		return (NULL);
	split_string = ft_fill_str(s, c, count_words, split_string);
	return (split_string);
}
