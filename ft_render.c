/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:07:47 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/13 13:44:32 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_img(char *img, int x, int y, t_data *data)
{
	int	w;
	int	h;

	x *= 48;
	y *= 48;
	data->mlx_img = mlx_xpm_file_to_image(data->mlx, img, &w, &h);
	if (data->mlx_img == (void *)0)
		ft_puterror_free("Error\nMlx image not found\n", data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, x, y);
	mlx_destroy_image(data->mlx, data->mlx_img);
}

void	ft_draw_walls(int x, int y, t_data *data)
{
	if (x == 0 && y == 0)
		ft_put_img(WALL_TLC, x, y, data);
	else if (x == 0 && y == data->game->height - 1)
		ft_put_img(WALL_BLC, x, y, data);
	else if (x == data->game->width - 1 && y == 0)
		ft_put_img(WALL_TRC, x, y, data);
	else if (x == data->game->width - 1 && y == data->game->height - 1)
		ft_put_img(WALL_BRC, x, y, data);
	else if (x == 0 && y > 0 && y < data->game->height - 1)
		ft_put_img(WALL_LEFT, x, y, data);
	else if (x == data->game->width - 1 && y > 0 && y < data->game->height - 1)
		ft_put_img(WALL_RIGHT, x, y, data);
	else if (y == 0 && x > 0 && x < data->game->width - 1)
		ft_put_img(WALL, x, y, data);
	else if (y == data->game->height - 1 && x > 0 && x < data->game->width - 1)
		ft_put_img(WALL, x, y, data);
	else
		ft_put_img(OBST, x, y, data);
}

void	ft_draw_map(int x, int y, char ch, t_data *data)
{
	if (ch == '0')
		ft_put_img(FLOOR, x, y, data);
	else if (ch == '1')
		ft_draw_walls(x, y, data);
	else if (ch == 'C')
		ft_put_img(COLLECT_1, x, y, data);
	else if (ch == 'P')
	{
		data->game->player_x = x;
		data->game->player_y = y;
		ft_put_img(PLAYER, x, y, data);
	}
	else if (ch == 'E')
		ft_put_img(EXIT_CLOSED, x, y, data);
}

void	ft_draw_background(char *img, t_data *data)
{
	int	w;
	int	h;

	h = 0;
	while (h < data->game->height)
	{
		w = 0;
		while (w < data->game->width)
		{
			ft_put_img(img, w, h, data);
			w++;
		}
		h++;
	}
}

void	ft_render(t_data *data)
{
	int		x;
	int		y;
	char	ch;

	mlx_clear_window(data->mlx, data->mlx_win);
	ft_draw_background(FLOOR, data);
	y = 0;
	while (y < data->game->height)
	{
		x = 0;
		while (x < data->game->width)
		{
			ch = data->game->map[y][x];
			ft_draw_map(x, y, ch, data);
			x++;
		}
		y++;
	}
}
