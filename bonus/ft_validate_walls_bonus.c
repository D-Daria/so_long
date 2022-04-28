/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_walls_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:18:48 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/12 15:47:09 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_validate_side_walls(t_data *data, int len)
{
	int	h;

	h = 1;
	while (h < data->game->height)
	{
		if (data->game->map[h][0] != '1')
			return (0);
		else if (data->game->map[h][len - 1] != '1')
			return (0);
		h += 1;
	}
	return (1);
}

int	ft_validate_walls(t_data *data, int *h, int *w, int len)
{
	*w = 0;
	while (data->game->map[0][*w] != '\n')
	{
		if (data->game->map[0][*w] != '1')
			return (0);
		*w += 1;
	}
	*w = 0;
	*h = data->game->height - 1;
	while (data->game->map[*h][*w] != '\n' &&
			data->game->map[*h][*w] != '\0')
	{
		if (data->game->map[*h][*w] != '1')
			return (0);
		*w += 1;
	}
	if (!(ft_validate_side_walls(data, len)))
		return (0);
	return (1);
}
