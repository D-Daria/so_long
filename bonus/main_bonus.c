/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:16:45 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/12 16:54:12 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc < 2)
		ft_puterror("Too few arguments. Try this: ./so_long [map.ber]\n");
	else if (argc > 2)
		ft_puterror("Too many arguments. Try this: ./so_long [map.ber]\n");
	ft_bzero(&data, sizeof(t_data));
	data.game = malloc(sizeof(t_game));
	if (data.game == NULL)
		ft_puterror("Error\nMemory malloc");
	ft_init_game(data.game);
	ft_read_map(&data, argv[1]);
	ft_mlx(&data);
	ft_exit(&data);
	return (0);
}
