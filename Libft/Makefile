# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 13:41:49 by tmagikar          #+#    #+#              #
#    Updated: 2020/11/19 17:07:57 by tmagikar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

INCLUDE = libft.h

SRC =	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memccpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strlen.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strnstr.c\
	ft_strncmp.c\
	ft_atoi.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isdigit.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\

OBJ_NAME	= $(SRC:.c=.o)

CFLAGS		= -Wall -Wextra -Werror -c

CC			= gcc $(CFLAGS)

RM			= rm -f

${NAME}:
			${CC} ${SRC}
			ar rc $(NAME) ${OBJ_NAME}

all:		${NAME}

clean:
			${RM} ${OBJ_NAME}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
