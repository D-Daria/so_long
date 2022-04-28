/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:38:39 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/01/20 19:07:00 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		s1_len;
	int		set_len;
	char	*new;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	set_len = ft_strlen(set);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	while (s1_len > 0 && ft_strchr(set, s1[s1_len]))
		s1_len--;
	new = ft_substr(s1, i, s1_len - i + 1);
	if (!new)
		return (NULL);
	return (new);
}
