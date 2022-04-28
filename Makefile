NAME = so_long

#---mandatory part---#
OBJS_DIR = objs

SRCS_MF =	main.c\
			ft_mlx.c ft_utils.c\
			ft_read_map.c ft_validate_map.c\
			ft_errors.c ft_validate_walls.c\
			ft_render.c ft_game_utils.c

OBJS_M = $(addprefix $(OBJS_DIR)/, $(patsubst %.c,%.o, $(SRCS_MF)))
D_FILES_M = $(addprefix $(OBJS_DIR)/, $(patsubst %.c,%.d, $(SRCS_MF)))

#---bonus part---#
NAME_B = so_long_bonus

BONUS_DIR = bonus
OBJS_B_DIR = bonus/objs

SRCS_B =	main_bonus.c\
			ft_utils_bonus.c\
			ft_validate_map_bonus.c ft_read_map_bonus.c\
			ft_validate_walls_bonus.c ft_errors_bonus.c\
			ft_mlx_bonus.c ft_render_bonus.c ft_game_utils_bonus.c\
			ft_move_bonus.c ft_animation_bonus.c ft_collect_anim_bonus.c\
			ft_enemies_bonus.c ft_villain_anim_bonus.c\
			ft_villain_dir_bonus.c

SRCS_BF = $(addprefix $(BONUS_DIR)/, $(SRCS_B))

OBJS_B = $(addprefix $(OBJS_B_DIR)/, $(patsubst %.c,%.o, $(SRCS_B)))
D_FILES_B = $(addprefix $(OBJS_B_DIR)/, $(patsubst %.c,%.d, $(SRCS_B)))

INCLUDES = -I ./mlx -I ./ -I libft/libft_includes/ -I ./bonus/

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT = ./libft/libft.a
LIB_INC = -L./libft/ -lft

#colors
RED 	= 	\033[0;31m
GREEN 	= 	\033[0;32m
BLUE	=	\033[0;34m
BREAK 	= 	\033[0m
YELLOW	=	\033[0;33m

OPFLAGS = -O2
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
SANIT_FLAGS = cc -fsanitize=address $(CFLAGS)

.PHONY : all lib bonus clean fclean sanit_m sanit_b re

all : lib $(NAME) bonus

norm :
	@norminette ./libft so_long.h ./bonus/so_long_bonus.h ./bonus/assets_bonus.h $(SRCS_BF) $(SRCS_MF) 

$(OBJS_DIR) :
	mkdir $@

$(OBJS_B_DIR) :
	mkdir -p bonus/objs

lib :
	make -C libft/

$(NAME) : $(OBJS_M) $(LIBFT)
	make -C ./mlx
	$(CC) $(CFLAGS) $(OPFLAGS) $(OBJS_M) $(LIB_INC) $(MLX) -o $(NAME)
	@echo "$(BLUE)$(NAME)$(GREEN) --> DONE!$(BREAK)"

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(OPFLAGS) $(INCLUDES) -c $< -o $@ -MD

bonus : lib $(NAME_B)

$(NAME_B) : $(OBJS_B) $(LIBFT)
	make -C ./mlx
	$(CC) $(CFLAGS) $(OPFLAGS) $(OBJS_B) $(LIB_INC) $(MLX) -o $(NAME_B)
	@echo "$(BLUE)$(NAME_B)$(GREEN) --> DONE!$(BREAK)"

$(OBJS_B_DIR)/%.o : $(BONUS_DIR)/%.c | $(OBJS_B_DIR)
	$(CC) $(CFLAGS) $(OPFLAGS) $(INCLUDES) -c $< -o $@ -MD

clean :
	make -C libft/ $@
	make -C ./mlx $@
	rm -rf $(OBJS_DIR)
	@echo "$(BLUE)objs $(RED)--> DELETED$(BREAK)"
	rm -rf $(OBJS_B_DIR)
	@echo "$(BLUE)bonus objs $(RED)--> DELETED$(BREAK)"

fclean : clean
	make -C libft/ $@
	@echo "$(BLUE)libft.a $(RED)--> DELETED$(BREAK)"
	rm -f $(NAME)
	@echo "$(BLUE)$(NAME) $(RED)--> DELETED$(BREAK)"
	rm -f $(NAME_B)
	@echo "$(BLUE)$(NAME_B) $(RED)--> DELETED$(BREAK)"

re : fclean all

sanit_m :
	$(SANIT_FLAGS) $(OBJS_M) $(LIB_INC) $(MLX) -o $(NAME)

sanit_b :
	$(SANIT_FLAGS) $(OBJS_B) $(LIB_INC) $(MLX) -o $(NAME_B)

include $(wildcard $(D_FILES_M))
include $(wildcard $(D_FILES_B))