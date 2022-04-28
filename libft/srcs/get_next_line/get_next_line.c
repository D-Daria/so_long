/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 01:34:21 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/03/31 19:28:46 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_delete_clear_line(char *save_line)
{
	char	*new_save_line;
	size_t	i;
	size_t	c;

	if (save_line == NULL)
		return (NULL);
	i = 0;
	while (save_line[i] != '\0' && save_line[i] != '\n')
		i++;
	if (save_line[i] == '\0')
	{
		free(save_line);
		return (NULL);
	}
	new_save_line = malloc(sizeof(char) * (ft_strlen(save_line) - i + 1));
	if (new_save_line == NULL)
		return (NULL);
	c = 0;
	i++;
	while (save_line[i] != '\0')
		new_save_line[c++] = save_line[i++];
	new_save_line[c] = '\0';
	free(save_line);
	return (new_save_line);
}

char	*ft_clear_save_line(char *save_line)
{
	char	*line;
	int		i;
	int		c;

	i = 0;
	if (save_line[i] == '\0')
		return (NULL);
	while (save_line[i] != '\0' && save_line[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	c = 0;
	while (save_line[i] != '\0' && save_line[i] != '\n')
		line[c++] = save_line[i++];
	if (save_line[i] == '\n')
		line[c++] = save_line[i++];
	line[c] = '\0';
	return (line);
}

char	*ft_read_from_buffer(int fd, char *save_line)
{
	char	*rd_buffer;
	int		bytes_read;

	rd_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (rd_buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, rd_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(rd_buffer);
			return (NULL);
		}
		rd_buffer[bytes_read] = '\0';
		save_line = ft_new_strjoin(save_line, rd_buffer);
		if (ft_has_new_line(save_line))
			break ;
	}
	free(rd_buffer);
	return (save_line);
}

char	*get_next_line(int fd)
{
	static char		*save_line;
	char			*clear_line;

	if (fd < 0)
		return (NULL);
	save_line = ft_read_from_buffer(fd, save_line);
	if (save_line == NULL)
		return (NULL);
	clear_line = ft_clear_save_line(save_line);
	save_line = ft_delete_clear_line(save_line);
	return (clear_line);
}
