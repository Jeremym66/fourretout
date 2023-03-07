# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 10:52:40 by jmetezea          #+#    #+#              #
#    Updated: 2023/03/07 15:21:57 by jmetezea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            = libftprintf.a

SRCS            = ft_strlen.c ft_printchar.c ft_printstr.c ft_printnbrbase.c ft_printnbr.c ft_printf.c

OBJS            = ${SRCS:.c=.o}

CFLAGS          = -Wall -Wextra -Werror

CC                      = gcc

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar -rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
	rm -f ${OBJS}

fclean:		clean
	rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re
