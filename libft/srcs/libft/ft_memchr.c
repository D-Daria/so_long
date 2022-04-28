/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:31:19 by mrhyhorn          #+#    #+#             */
/*   Updated: 2021/10/08 18:32:51 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str2;

	i = 0;
	str2 = (unsigned char *)s;
	while (n > i)
	{
		if (str2[i] == (unsigned char)c)
			return (&str2[i]);
		i++;
	}
	return (NULL);
}
