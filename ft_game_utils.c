/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:37:17 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/05 16:14:24 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		ft_putstr_fd("Congrats! You opened the door in ", 1);
		ft_putnbr_fd(data->game->moves, 1);
		if (data->game->moves == 1)
			ft_putstr_fd(" move\n", 1);
		else
			ft_putstr_fd(" moves\n", 1);
	}
	ft_putstr_fd(BREAK, 1);
}

void	ft_print_moves(t_data *data)
{
	ft_putstr_fd(YELLOW, 1);
	ft_putstr_fd("You made ", 1);
	ft_putnbr_fd(data->game->moves, 1);
	if (data->game->moves == 1)
		ft_putstr_fd(" move\r", 1);
	else
		ft_putstr_fd(" moves\r", 1);
	ft_putstr_fd(BREAK, 1);
}
