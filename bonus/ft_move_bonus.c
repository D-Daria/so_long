/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:09:49 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/06 17:17:40 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_move_player(int x, int y, t_data *data)
{
	ft_print_moves(data);
	if (data->game->current_key == UP)
		ft_put_img(PLAYER_UP, x, y, data);
	else if (data->game->current_key == LEFT)
		ft_put_img(PLAYER_LEFT, x, y, data);
	else if (data->game->current_key == DOWN)
		ft_put_img(PLAYER_DOWN, x, y, data);
	else
		ft_put_img(PLAYER, x, y, data);
}

static void	ft_move_collect(int x, int y, t_data *data)
{
	ft_put_img(FLOOR, x, y, data);
	ft_put_img(FLOOR, data->game->player_x, data->game->player_y, data);
	ft_move_player(x, y, data);
	data->game->map[y][x] = '0';
	data->game->collect -= 1;
}

static void	ft_move_space(int x, int y, t_data *data)
{
	ft_put_img(FLOOR, data->game->player_x, data->game->player_y, data);
	ft_move_player(x, y, data);
}

static void	ft_move_villain(t_data *data)
{
	ft_game_msg(data, 'V');
	ft_exit(data);
}

void	ft_move(int x, int y, t_data *data)
{
	if (data->game->map[y][x] == '1')
		return ;
	else if (data->game->map[y][x] == 'E' && data->game->collect != 0)
	{
		ft_game_msg(data, 'k');
		return ;
	}
	else if (data->game->map[y][x] == 'E' && data->game->collect == 0)
	{
		ft_game_msg(data, 'e');
		ft_exit(data);
	}
	else if (data->game->map[y][x] == '0')
		ft_move_space(x, y, data);
	else if (data->game->map[y][x] == 'C')
		ft_move_collect(x, y, data);
	else if (data->game->map[y][x] == 'V')
		ft_move_villain(data);
	data->game->player_x = x;
	data->game->player_y = y;
}
