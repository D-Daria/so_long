/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_villain_anim_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:28:54 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/12 18:51:04 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_villain_y(int y, t_enemy *temp, t_data *data)
{
	if (data->game->map[y][temp->enemy_x] == 'C')
	{
		data->game->map[temp->enemy_y][temp->enemy_x] = '0';
		data->game->map[y][temp->enemy_x] = 'V';
		ft_put_img(KEY_S1, temp->enemy_x, temp->enemy_y, data);
		ft_put_img(VILLAIN_1, temp->enemy_x, y, data);
	}
	else
	{
		data->game->map[temp->enemy_y][temp->enemy_x] = '0';
		data->game->map[y][temp->enemy_x] = 'V';
		ft_put_img(FLOOR, temp->enemy_x, temp->enemy_y, data);
		ft_put_img(VILLAIN_1, temp->enemy_x, y, data);
	}
	temp->enemy_y = y;
	if (data->game->map[temp->enemy_y][temp->enemy_x] \
		== data->game->map[data->game->player_y][data->game->player_x])
	{
		ft_game_msg(data, 'V');
		ft_exit(data);
	}
}

static void	ft_villain_x(int x, t_enemy *temp, t_data *data)
{
	if (data->game->map[temp->enemy_y][x] == 'C')
	{
		data->game->map[temp->enemy_y][temp->enemy_x] = 'C';
		data->game->map[temp->enemy_y][x] = 'V';
		ft_put_img(KEY_S1, temp->enemy_x, temp->enemy_y, data);
		ft_put_img(VILLAIN_1, x, temp->enemy_y, data);
	}
	else if (data->game->map[temp->enemy_y][x] == '0')
	{
		data->game->map[temp->enemy_y][temp->enemy_x] = '0';
		data->game->map[temp->enemy_y][x] = 'V';
		ft_put_img(FLOOR, temp->enemy_x, temp->enemy_y, data);
		ft_put_img(VILLAIN_1, x, temp->enemy_y, data);
	}
	temp->enemy_x = x;
	if (data->game->map[temp->enemy_y][temp->enemy_x] \
		== data->game->map[data->game->player_y][data->game->player_x])
	{
		ft_game_msg(data, 'V');
		ft_exit(data);
	}
}

static void	ft_set_limit(int *limit, t_data *data)
{
	if (data->game->collect == 0)
		*limit = 30;
	else
		*limit = 4000;
}

void	ft_villain_anim(t_data *data)
{
	static int	i;
	int			flag;
	int			limit;
	t_enemy		*temp;

	temp = data->enemy;
	ft_set_limit(&limit, data);
	i += 1;
	while (temp)
	{
		ft_check_villain_dir(temp, data, &flag);
		if (flag == DOWN && i == limit)
			ft_villain_y(temp->enemy_y + 1, temp, data);
		if (flag == UP && i == limit)
			ft_villain_y(temp->enemy_y - 1, temp, data);
		if (flag == RIGHT && i == limit)
			ft_villain_x(temp->enemy_x + 1, temp, data);
		if (flag == LEFT && i == limit)
			ft_villain_x(temp->enemy_x - 1, temp, data);
		temp = temp->next;
	}
	if (i > limit)
		i = 0;
}
