NAME =	philo

INCLUDE = philo.h

SRC =		philo.c \
			ft_status.c \
			utils.c \
			ft_arg_param.c \

OBJ_NAME	= $(SRC:.c=.o)

CC			= gcc -g -Wall -Wextra -Werror
# -pthread

RM			= rm -f

$(NAME):	$(OBJ_NAME) $(INCLUDE)
			$(CC) -o $(NAME) $(OBJ_NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJ_NAME) 

fclean:		clean
			$(RM) ${NAME} 

re:			fclean all
