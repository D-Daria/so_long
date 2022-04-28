/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:44:34 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/11 16:08:42 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_open_door(t_data *data)
{
	int	h;
	int	w;

	h = 0;
	while (h < data->game->height)
	{
		w = 0;
		while (w < data->game->width)
		{
			if (data->game->map[h][w] == 'E')
				ft_put_img(EXIT_OPEN_CHEST, w, h, data);
			w++;
		}
		h++;
	}
}

int	ft_animation(t_data *data)
{
	ft_collect_animation(data);
	ft_villain_anim(data);
	if (data->game->collect == 0)
		ft_open_door(data);
	return (0);
}
