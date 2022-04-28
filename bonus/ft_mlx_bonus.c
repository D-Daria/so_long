/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:16:40 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/11 16:03:57 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_assign_key(int key, t_data *data)
{
	if (key == W || key == UP)
		data->game->current_key = UP;
	else if (key == A || key == LEFT)
		data->game->current_key = LEFT;
	else if (key == S || key == DOWN)
		data->game->current_key = DOWN;
	else if (key == D || key == RIGHT)
		data->game->current_key = RIGHT;
}

static int	ft_key(int key, t_data *data)
{
	int	x;
	int	y;

	ft_assign_key(key, data);
	x = data->game->player_x;
	y = data->game->player_y;
	data->game->map[y][x] = '0';
	if (key == ESC || key == Q)
	{
		ft_game_msg(data, 'q');
		ft_exit(data);
	}
	else if (key == W || key == UP)
		ft_move(x, y - 1, data);
	else if (key == A || key == LEFT)
		ft_move(x - 1, y, data);
	else if (key == S || key == DOWN)
		ft_move(x, y + 1, data);
	else if (key == D || key == RIGHT)
		ft_move(x + 1, y, data);
	return (0);
}

void	ft_mlx(t_data *data)
{
	int	win_h;
	int	win_w;

	win_h = data->game->height;
	win_w = data->game->width;
	data->mlx = mlx_init();
	if (data->mlx == (void *)0)
		ft_puterror_free("Error\n", data);
	data->mlx_win = mlx_new_window(data->mlx, \
				win_w * ASSET_SIZE, win_h * ASSET_SIZE, GAME_NAME_B);
	if (data->mlx_win == (void *)0)
		ft_puterror_free("Error\n", data);
	if (data->game->villain_num > 0)
	{
		data->enemy = ft_init_enemies(data);
		if (data->enemy == NULL)
			ft_puterror_free("Enemies error\n", data);
	}
	ft_render(data);
	mlx_key_hook(data->mlx_win, ft_key, data);
	mlx_loop_hook(data->mlx, ft_animation, data);
	mlx_hook(data->mlx_win, 17, 0, ft_exit, data);
	mlx_loop(data->mlx);
}
