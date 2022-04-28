/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:44:41 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/05 15:50:18 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_validate_file_ext(char *file)
{
	char	*dot;

	dot = NULL;
	dot = ft_strchr(file, '.');
	if (dot == NULL)
		return (0);
	if ((ft_strcmp(".ber", dot)) == 0)
		return (1);
	return (0);
}

static void	ft_get_height(t_data *data, char *file)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_puterror("Error\nFile openning\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->game->height += 1;
		free(line);
		line = NULL;
	}
	close(fd);
}

static void	ft_parse_map(t_data *data, char *file)
{
	int		fd;
	char	*line;
	int		h;

	line = NULL;
	h = data->game->height;
	data->game->map = (char **)malloc(sizeof(char *) * (h + 1));
	if (data->game->map == NULL)
		ft_puterror("Error\nMemory malloc");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_puterror("Error\nFile openning\n");
	h = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->game->map[h] = ft_strdup(line);
		h++;
		free(line);
		line = NULL;
	}
	data->game->map[h] = 0;
	close(fd);
}

int	ft_read_map(t_data *data, char *file)
{
	int	out;

	if (!(ft_validate_file_ext(file)))
		ft_puterror("Error\nInvalid file extension\n");
	ft_get_height(data, file);
	if (data->game->height == 0)
		ft_puterror("Error\nMap is empty\n");
	ft_parse_map(data, file);
	out = ft_validate_map(data);
	if (out > 0)
		ft_display_error(out, data);
	return (0);
}
