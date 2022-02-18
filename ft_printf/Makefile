# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/29 16:19:37 by tmagikar          #+#    #+#              #
#    Updated: 2021/01/23 20:07:57 by tmagikar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

INCLUDE = ft_printf.h

SRC =	*.c\

OBJ_NAME	= $(SRC:.c=.o)

OO =	*.o

CFLAGS		= -Wall -Wextra -Werror -c

CC			= gcc $(CFLAGS)

RM			= rm -f

${NAME}:	${SRC} ${INCLUDE}
			${CC} ${SRC}
			ar rc $(NAME) ${OBJ_NAME}

all:		${NAME}

bonus:		${NAME}

clean:
			${RM} ${OO}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
