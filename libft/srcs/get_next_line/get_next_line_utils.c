/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 02:11:27 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/05 15:26:06 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (s == NULL && d == NULL)
		return (NULL);
	i = 0;
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char	*ft_new_strjoin(char *save_line, char *rd_buffer)
{
	char	*new;
	int		i;

	if (save_line == NULL)
	{
		save_line = malloc(sizeof(char) * 1);
		if (save_line == NULL)
			return (NULL);
		save_line[0] = '\0';
	}
	if (rd_buffer == NULL)
		return (NULL);
	new = malloc(sizeof(char)
			* (ft_strlen(save_line) + ft_strlen(rd_buffer) + 1));
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, save_line, (ft_strlen(save_line) + 1));
	i = ft_strlen(new);
	ft_memcpy(&new[i], rd_buffer, (ft_strlen(rd_buffer) + 1));
	free(save_line);
	return (new);
}

int	ft_has_new_line(char *save_line)
{
	int	i;

	if (save_line == NULL)
		return (0);
	i = 0;
	while (save_line[i] != '\0')
	{
		if (save_line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
