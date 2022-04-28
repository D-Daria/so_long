/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect_anim_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:06:16 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/11 16:09:24 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_s_key_rotation(int i, int w, int h, t_data *data)
{
	if (i == 0)
		ft_put_img(KEY_S1, w, h, data);
	else if (i == 2500)
		ft_put_img(KEY_S2, w, h, data);
	else if (i == 4500)
		ft_put_img(KEY_S3, w, h, data);
	else if (i == 6500)
		ft_put_img(KEY_S4, w, h, data);
	else if (i == 8500)
		ft_put_img(KEY_S5, w, h, data);
	else if (i == 10500)
		ft_put_img(KEY_S6, w, h, data);
	else if (i == 12500)
		ft_put_img(KEY_S1, w, h, data);
}

static void	ft_g_key_rotation(int i, int w, int h, t_data *data)
{
	if (i == 0)
		ft_put_img(KEY_G1, w, h, data);
	else if (i == 2500)
		ft_put_img(KEY_G2, w, h, data);
	else if (i == 4500)
		ft_put_img(KEY_G3, w, h, data);
	else if (i == 6500)
		ft_put_img(KEY_G4, w, h, data);
	else if (i == 8500)
		ft_put_img(KEY_G5, w, h, data);
	else if (i == 10500)
		ft_put_img(KEY_G6, w, h, data);
	else if (i == 12500)
		ft_put_img(KEY_G1, w, h, data);
}

static void	ft_anim_g_key(t_data *data)
{
	static int	i;
	int			h;
	int			w;

	h = 0;
	while (h < data->game->height)
	{
		w = 0;
		while (w < data->game->width)
		{
			if (data->game->map[h][w] == 'C')
				ft_g_key_rotation(i, w, h, data);
			w += 1;
		}
		h += 1;
	}
	i += 1;
	if (i > 12500)
		i = 0;
}

static void	ft_anim_s_key(t_data *data)
{
	static int	i;
	int			h;
	int			w;

	h = 0;
	while (h < data->game->height)
	{
		w = 0;
		while (w < data->game->width)
		{
			if (data->game->map[h][w] == 'C')
				ft_s_key_rotation(i, w, h, data);
			w += 1;
		}
		h += 1;
	}
	i += 1;
	if (i > 12500)
		i = 0;
}

void	ft_collect_animation(t_data *data)
{
	if (data->game->collect > 1)
		ft_anim_s_key(data);
	else if (data->game->collect == 1)
		ft_anim_g_key(data);
}
