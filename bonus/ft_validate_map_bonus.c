/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:29:16 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/11 16:12:00 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_check_chars(t_data *data)
{
	int	h;
	int	w;

	h = 0;
	while (h < data->game->height)
	{
		w = 0;
		while (data->game->map[h][w] != '\n' &&
				data->game->map[h][w] != '\0')
		{
			if (ft_strchr(CHARS_B, data->game->map[h][w]) == NULL)
				return (0);
			w++;
		}
		h++;
	}
	return (1);
}

static int	ft_check_char(t_data *data, char ch, int *count)
{
	int	h;
	int	w;

	*count = 0;
	h = 0;
	while (h < data->game->height)
	{
		w = 0;
		while (data->game->map[h][w] != '\0')
		{
			if (data->game->map[h][w] == ch)
				*count += 1;
			w += 1;
		}
		h += 1;
	}
	if (ch == 'P' && (*count > 1 || *count == 0))
		return (0);
	else if (*count == 0)
		return (0);
	return (1);
}

static int	ft_check_every_char(t_data *data)
{
	int	count;

	if (!(ft_check_chars(data)))
		return (INVALID_CHARS);
	if (!(ft_check_char(data, 'P', &count)))
		return (PLAYER_ERROR);
	if (!(ft_check_char(data, 'E', &count)))
		return (EXIT_ERROR);
	if (!(ft_check_char(data, 'C', &count)))
		return (COLLECT_ERROR);
	else
		data->game->collect = count;
	if ((ft_check_char(data, 'V', &count)))
		data->game->villain_num = count;
	return (VALID);
}

int	ft_validate_map(t_data *data)
{
	int		h;
	int		w;
	size_t	len;
	int		out;

	len = ft_strlen_nl(data->game->map[0]);
	h = 0;
	while (h < data->game->height)
	{
		if ((ft_strlen_nl(data->game->map[h])) != len)
			return (INVALID_RECT);
		h++;
	}
	data->game->width = (int)len;
	if (!(ft_validate_walls(data, &h, &w, len)))
		return (INVALID_WALLS);
	out = ft_check_every_char(data);
	if (out > 0)
		return (out);
	return (VALID);
}
