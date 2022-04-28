/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:18:41 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/05 17:35:15 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_game(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->collect = 0;
	game->moves = 0;
}

size_t	ft_strlen_nl(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		++i;
	return (i);
}

void	ft_free_split(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->game->height)
	{
		free(data->game->map[i]);
		i++;
	}
	free(data->game->map);
	data->game->map = NULL;
}

int	ft_exit(t_data *data)
{
	ft_free_split(data);
	free(data->game);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(EXIT_SUCCESS);
}
