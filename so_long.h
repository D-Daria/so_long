/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:52:05 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/13 13:43:21 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define WIN_MAX_WIDTH 1240
# define WIN_MAX_HEIGHT 600
# define CHARS "01CEP"
# define GAME_NAME "><> |so_long| <><"

/*---ASSESTS---*/
# define ASSET_SIZE 48

# define COLLECT_1	"assets/collect/key_s1.xpm"

# define FLOOR		"assets/floor/floor.xpm"

# define OBST		"assets/walls/barrel.xpm"
# define WALL_TLC	"assets/walls/top_left_corner.xpm"
# define WALL_TRC	"assets/walls/top_right_corner.xpm"
# define WALL_BLC	"assets/walls/bottom_left_corner.xpm" 
# define WALL_BRC	"assets/walls/bottom_right_corner.xpm"
# define WALL_LEFT	"assets/walls/wall_left_torch.xpm"
# define WALL_RIGHT "assets/walls/wall_right_torch.xpm"
# define WALL		"assets/walls/wall.xpm"

# define PLAYER		"assets/player/knight_idle.xpm"

# define EXIT_CLOSED	"assets/exit/door_closed.xpm"

/*---KEYS---*/
# define Q		12
# define ESC	53
# define W		13
# define A		0
# define S		1
# define D		2
# define LEFT	123
# define RIGHT	124
# define DOWN	125
# define UP		126
# define SPACE	49

/*---ERRORS---*/
# define VALID			0
# define INVALID_RECT	3 
# define INVALID_WALLS	4
# define INVALID_CHARS	5
# define PLAYER_ERROR	6
# define EXIT_ERROR		7
# define COLLECT_ERROR	8

/*---COLORS---*/
# define RED	"\033[0;31m"
# define YELLOW	"\033[0;33m"
# define BREAK	"\033[0m"

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		moves;
	int		collect;
}			t_game;

typedef struct s_data {
	void		*mlx;
	void		*mlx_win;
	void		*mlx_img;
	t_game		*game;
}				t_data;

/*ft_read_map.c*/
int		ft_read_map(t_data *data, char *file);

/*ft_validate_map.c*/
int		ft_validate_map(t_data *data);

/*ft_validate_walls.c*/
int		ft_validate_walls(t_data *data, int *h, int *w, int len);

/*ft_mlx.c*/
void	ft_mlx(t_data *data);

/*ft_render.c*/
void	ft_render(t_data *data);
void	ft_put_img(char *img, int x, int y, t_data *data);

/*ft_utils.c*/
void	ft_free_split(t_data *data);
void	ft_init_game(t_game *game);
size_t	ft_strlen_nl(char *s);
int		ft_exit(t_data *data);

/*ft_game_utils.c*/
void	ft_print_moves(t_data *data);
void	ft_game_msg(t_data *data, char c);

/*ft_errors.c*/
void	ft_display_error(int e, t_data *data);
void	ft_puterror(const char *error);
void	ft_puterror_free(const char *error, t_data *data);

#endif