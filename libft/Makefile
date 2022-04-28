###########################
#         NAME            #
###########################
NAME =  	libft.a

###########################
#         DIRS            #
###########################
DIR_LIB_SRCS = srcs/
DIR_LIBFT = libft/
DIR_GNL = get_next_line/
DIR_FTPF = ft_printf/

###########################
#         FILES           #
###########################
LIBFT_FILES =  ft_abs.c ft_atoi.c ft_atol.c\
			ft_atoll.c ft_bzero.c ft_calloc.c\
			ft_isalnum.c ft_isalpha.c ft_isascii.c\
			ft_isdigit.c ft_isprint.c ft_memchr.c\
			ft_memcmp.c ft_memcpy.c ft_memmove.c\
			ft_memset.c ft_strchr.c ft_strdup.c\
			ft_strlcat.c ft_strlcpy.c ft_strcpy.c ft_strlen.c\
			ft_strncmp.c ft_strcmp.c ft_strnstr.c ft_strrchr.c\
			ft_tolower.c ft_toupper.c ft_substr.c\
			ft_strjoin.c ft_strtrim.c ft_split.c\
			ft_itoa.c ft_strmapi.c ft_striteri.c\
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
			ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c\
			ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\
			ft_max.c ft_fmax.c

GNL_FILES = get_next_line.c get_next_line_utils.c

FT_PRINTF_FILES = 	ft_printf.c\
					ft_putchar.c ft_puthex.c ft_putnbr.c\
					ft_putptr.c ft_putstr.c ft_putuint.c

HEADERS = 	-I ./libft_includes/

C_FILES_LIBFT = $(addprefix $(DIR_LIBFT), $(LIBFT_FILES))
O_FILES_LIBFT = $(C_FILES_LIBFT:.c=.o)
D_FILES_LIBFT = $(C_FILES_LIBFT:.c=.d)

C_FILES_GNL = $(addprefix $(DIR_GNL), $(GNL_FILES))
O_FILES_GNL = $(C_FILES_GNL:.c=.o)
D_FILES_GNL = $(C_FILES_GNL:.c=.d)

C_FILES_FTPF = $(addprefix $(DIR_FTPF), $(FT_PRINTF_FILES))
O_FILES_FTPF = $(C_FILES_FTPF:.c=.o)
D_FILES_FTPF = $(C_FILES_FTPF:.c=.d)

SRCS_ALL = $(addprefix $(DIR_LIB_SRCS), $(C_FILES_LIBFT) $(C_FILES_GNL) $(C_FILES_FTPF))
OBJ_ALL = $(addprefix $(DIR_LIB_SRCS), $(O_FILES_LIBFT) $(O_FILES_GNL) $(O_FILES_FTPF))
D_FILES_ALL = $(addprefix $(DIR_LIB_SRCS), $(D_FILES_LIBFT) $(D_FILES_GNL) $(D_FILES_FTPF))

CFLAGS = -Wall -Wextra -Werror

GREEN 	= 	\033[0;32m
BREAK 	= 	\033[0m
BLUE	=	\033[0;34m

all : $(NAME)

$(NAME) : $(OBJ_ALL)
	ar rc $(NAME) $?
	ranlib $(NAME)
	@echo "$(BLUE)$(NAME)$(GREEN) --> DONE!$(BREAK)"

%.o : %.c
	cc $(CFLAGS) $(HEADERS) -c $< -o $@ -MD

clean :
	rm -f $(OBJ_ALL) $(D_FILES_ALL)

fclean : clean
	rm -f $(NAME)

re : fclean all

include $(wildcard $(D_FILES_ALL))

.PHONY : all clean fclean re
