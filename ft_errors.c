/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:01:46 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/05 15:56:45 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_puterror_free(const char *error, t_data *data)
{
	ft_free_split(data);
	free(data->game);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(BREAK, 2);
	exit(EXIT_FAILURE);
}

void	ft_display_error(int e, t_data *data)
{
	if (e == INVALID_RECT)
		ft_puterror_free("Error\nMap is not rectangular\n", data);
	else if (e == INVALID_WALLS)
		ft_puterror_free("Error\nInvalid walls\n", data);
	else if (e == INVALID_CHARS)
		ft_puterror_free("Error\nMap has invalid characters\n", data);
	else if (e == PLAYER_ERROR)
		ft_puterror_free("Error\nMultiple players\n", data);
	else if (e == EXIT_ERROR)
		ft_puterror_free("Error\nMap has no exit\n", data);
	else if (e == COLLECT_ERROR)
		ft_puterror_free("Error\nMap has no collectibles\n", data);
}

void	ft_puterror(const char *error)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(BREAK, 2);
	exit(EXIT_FAILURE);
}
