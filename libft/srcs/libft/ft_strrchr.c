/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:57:40 by mrhyhorn          #+#    #+#             */
/*   Updated: 2021/10/08 13:58:49 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*found;

	found = (char *)str;
	i = 0;
	while (str[i] != '\0')
		i++;
	i += 1;
	while (i > 0)
	{
		i--;
		if (str[i] == (char)c)
			return (found + i);
	}
	return (NULL);
}
