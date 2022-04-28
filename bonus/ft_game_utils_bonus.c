/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:37:17 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/11 16:10:11 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_game(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->collect = 0;
	game->moves = 0;
	game->current_key = 0;
	game->villain_x = 0;
	game->villain_y = 0;
	game->villain_num = 0;
}

void	ft_game_msg(t_data *data, char c)
{
	ft_putstr_fd(YELLOW, 1);
	if (data->game->collect != 0 && c == 'k')
	{
		ft_putstr_fd("Door is closed. Collect all keys : ", 1);
		ft_putnbr_fd(data->game->collect, 1);
		ft_putstr_fd(" left\n", 1);
	}
	else if (c == 'q')
		ft_putstr_fd("Quit game            \n", 1);
	else if (data->game->collect == 0 && c == 'e')
	{
		ft_putstr_fd("Congrats! You escaped in ", 1);
		ft_putnbr_fd(data->game->moves, 1);
		if (data->game->moves == 1)
			ft_putstr_fd(" move\n", 1);
		else
			ft_putstr_fd(" moves\n", 1);
	}
	else if (c == 'V')
		ft_putstr_fd("Oh no! Goblin captured you!\n", 1);
	ft_putstr_fd(BREAK, 1);
}

void	ft_print_moves(t_data *data)
{
	char	*moves;

	data->game->moves += 1;
	moves = ft_itoa(data->game->moves);
	ft_put_img(INFO_TAB, 0, 0, data);
	mlx_string_put(data->mlx, data->mlx_win, 15, 24, 0x545252, moves);
	free(moves);
	moves = NULL;
}
