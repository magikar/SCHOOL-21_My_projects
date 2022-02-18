NAME =	cub3D

INCLUDE = cub3d.h

SRC =	main.c ft_new_img.c mall_spr_space.c get_screenshot.c ft_map_in_buf.c ft_run.c\
		ft_verline.c ft_loading_texture.c ft_sort_sprits.c ft_key.c\
		ft_read_file_and_exit.c ft_buf_utils.c ft_check_len_map.c\
		ft_param_walls.c ft_param_sprites.c ft_check_pos.c ft_check_map.c\
		libft/ft_isdigit.c libft/ft_split.c libft/ft_strdup.c libft/ft_strjoin.c\
		libft/ft_substr.c libft/ft_strlen.c libft/ft_memcmp.c libft/ft_atoi.c

OBJ_NAME	= $(SRC:.c=.o)

CC			= gcc -g -Wall -Wextra -Werror

RM			= rm -f

LIBX		= libmlx.a -framework OpenGL -framework AppKit

LIBFT		= ./libft/libft.a

$(NAME):	$(LIBFT) $(OBJ_NAME)  $(LIBFT)
	$(CC) -o $(NAME) $(OBJ_NAME) $(LIBX)

$(LIBFT):
			$(MAKE) -C libft

all:		$(NAME)

bonus:		$(NAME)

clean:
			$(RM) $(OBJ_NAME)

fclean:		clean
			$(RM) ${NAME}

re:			fclean all