# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 10:52:40 by jmetezea          #+#    #+#              #
#    Updated: 2023/05/12 17:22:34 by kaly             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            = printf.a

SRCS            = ft_strlen.c ft_printchar.c ft_printstr.c ft_printnbrbase.c ft_printnbr.c ft_printf.c\
		  ft_printnbrhexa.c

OBJ		= ${SRCS:.c=.o}

CFLAGS          = -Wall -Wextra -Werror

CC                      = gcc

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ}
	ar -rcs ${NAME} ${OBJ}

all:		${NAME}

clean:
	rm -f ${OBJ}

fclean:		clean
	rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re
