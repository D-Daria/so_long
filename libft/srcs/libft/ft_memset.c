/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:32:37 by mrhyhorn          #+#    #+#             */
/*   Updated: 2021/10/07 14:46:13 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*arr;
	int				i;

	arr = (unsigned char *)b;
	i = 0;
	while (len > 0)
	{
		arr[i++] = (unsigned char)c;
		len--;
	}
	return (b);
}
