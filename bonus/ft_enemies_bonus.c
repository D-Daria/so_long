/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemies_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:04:27 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/11 16:09:46 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_push_enemy(t_enemy **first_enemy, t_enemy *new_enemy)
{
	t_enemy	*temp;

	if (*first_enemy == NULL)
		*first_enemy = new_enemy;
	else
	{
		temp = *first_enemy;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_enemy;
	}
}

static t_enemy	*ft_new_enemy(int x, int y)
{
	t_enemy	*new_enemy;

	new_enemy = malloc(sizeof(t_enemy));
	if (new_enemy == NULL)
		return (NULL);
	new_enemy->enemy_x = x;
	new_enemy->enemy_y = y;
	new_enemy->next = NULL;
	return (new_enemy);
}

void	ft_print_enemies(t_data *data)
{
	t_enemy	*temp;

	temp = data->enemy;
	while (temp)
	{
		ft_printf("enemy_x: %d\n", temp->enemy_x);
		temp = temp->next;
	}
}

t_enemy	*ft_init_enemies(t_data *data)
{
	int		x;
	int		y;
	t_enemy	*new_enemy;

	y = 0;
	while (y < data->game->height)
	{
		x = 0;
		while (x < data->game->width)
		{
			if (data->game->map[y][x] == 'V')
			{
				new_enemy = ft_new_enemy(x, y);
				ft_push_enemy(&data->enemy, new_enemy);
				new_enemy = NULL;
			}
			x += 1;
		}
		y += 1;
	}
	return (data->enemy);
}
