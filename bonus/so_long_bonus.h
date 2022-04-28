/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:25:04 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/12 16:11:43 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft.h"
# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/*---ASSESTS---*/
# include "assets_bonus.h"

# define WIN_MAX_WIDTH 1240
# define WIN_MAX_HEIGHT 800
# define CHARS_B "01CEPV"
# define GAME_NAME_B "><> |so_long_bonus| <><"

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

/*---COLORS---*/
# define RED	"\033[0;31m"
# define YELLOW	"\033[0;33m"
# define BREAK	"\033[0m"

/*---ERRORS---*/
# define VALID			0
# define INVALID_RECT	3 
# define INVALID_WALLS	4
# define INVALID_CHARS	5
# define PLAYER_ERROR	6
# define EXIT_ERROR		7
# define COLLECT_ERROR	8

typedef struct s_enemy {
	int				enemy_x;
	int				enemy_y;
	void			*enemy_img;
	struct s_enemy	*next;
}					t_enemy;

typedef struct s_enemy_img {
	int				enemy_num;
	void			*enemy_img;
	struct s_enemy	*next;
}					t_enemy_img;

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collect;
	int		moves;
	int		villain_num;
	int		villain_x;
	int		villain_y;
	int		current_key;
}			t_game;

typedef struct s_data {
	void		*mlx;
	void		*mlx_win;
	void		*mlx_img;
	t_game		*game;
	t_enemy		*enemy;
}				t_data;

/*ft_read_map_bonus.c*/
int		ft_read_map(t_data *data, char *file);

/*ft_validate_map_bonus.c*/
int		ft_validate_map(t_data *data);

/*ft_validate_walls_bonus.c*/
int		ft_validate_walls(t_data *data, int *h, int *w, int len);

/*ft_mlx_bonus.c*/
void	ft_mlx(t_data *data);

/*ft_move_bonus.c*/
void	ft_move(int x, int y, t_data *data);

/*ft_render_bonus.c*/
int		ft_render(t_data *data);
void	ft_put_img(char *img, int x, int y, t_data *data);
void	ft_put_img_test(char *img, int x, int y, t_data *data);

/*ft_enemies_bonus.c*/
t_enemy	*ft_init_enemies(t_data *data);
void	ft_print_enemies(t_data *data);

/*ft_animation_bonus.c*/
int		ft_animation(t_data *data);

/*ft_key_anim_bonus.c*/
void	ft_collect_animation(t_data *data);

/*ft_villain_anim_bonus.c*/
void	ft_villain_anim(t_data *data);

/*ft_villain_dir_bonus.c*/
void	ft_check_villain_dir(t_enemy *temp, t_data *data, int *flag);

/*ft_utils_bonus.c*/
void	ft_free_split(t_data *data);
void	ft_delete_list(t_enemy **head);
size_t	ft_strlen_nl(char *s);
int		ft_exit(t_data *data);

/*ft_game_utils_bonus.c*/
void	ft_init_game(t_game *game);
void	ft_print_moves(t_data *data);
void	ft_game_msg(t_data *data, char c);

/*ft_errors_bonus.c*/
void	ft_puterror(const char *error);
void	ft_puterror_free(const char *error, t_data *data);
void	ft_display_error(int e, t_data *data);

#endif