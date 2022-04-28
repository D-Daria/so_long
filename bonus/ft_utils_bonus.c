/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:18:41 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/11 16:05:20 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	ft_delete_list(t_enemy **head)
{
	t_enemy	*next;

	if (*head != NULL)
	{
		while (*head != NULL)
		{
			next = (*head)->next;
			free(*head);
			*head = NULL;
			*head = next;
		}
	}
	free(*head);
	*head = NULL;
}

int	ft_exit(t_data *data)
{
	ft_free_split(data);
	if (data->enemy != NULL)
		ft_delete_list(&data->enemy);
	free(data->game);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(EXIT_SUCCESS);
}
