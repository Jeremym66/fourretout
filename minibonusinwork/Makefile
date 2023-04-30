# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaly <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 21:02:17 by kaly              #+#    #+#              #
#    Updated: 2023/04/29 11:35:57 by jmetezea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_SRCS	= src/client.c src/utils.c
SERVER_SRCS	= src/server.c src/utils.c
HEADERS		= head/minitalk.h

OBJS_CLIENT	= ${CLIENT_SRCS:.c=.o}
OBJS_SERVER	= ${SERVER_SRCS:.c=.o}

CFLAGS		= -Wall -Wextra -Werror
CC		= gcc
CC_FLAGS	= -Llibft -lft

%.o: %.c ${HEADERS} libft/libft.a
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		server client

server:		${OBJS_SERVER} ${HEADERS}
			make -C libft
			${CC} ${CFLAGS} ${CCFLAGS} ${SERVER_SRCS} -o server libft/libft.a

client:		${OBJS_CLIENT} ${HEADERS}
			${CC} ${CFLAGS} ${CCFLAGS} ${CLIENT_SRCS} -o client libft/libft.a

clean:
			rm -f ${OBJS_CLIENT} ${OBJS_SERVER}
			make clean -C libft

fclean:		clean
			rm -f client server
			make fclean -C libft

re:			fclean all

.PHONY: all clean fclean re
