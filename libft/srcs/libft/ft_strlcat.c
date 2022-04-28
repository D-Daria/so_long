/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:17:49 by mrhyhorn          #+#    #+#             */
/*   Updated: 2021/10/07 19:19:19 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	dest_len = ft_strlen(dst);
	i = dest_len;
	src_len = ft_strlen(src);
	if (dstsize < dest_len + 1)
		return (src_len + dstsize);
	else
	{
		dstsize = dstsize - dest_len - 1;
		while (src[c] != '\0' && dstsize > 0)
		{
			dst[i++] = src[c++];
			dstsize--;
		}
		dst[i] = '\0';
	}
	return (dest_len + src_len);
}
