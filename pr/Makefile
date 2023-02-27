# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maserrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 17:56:37 by maserrie          #+#    #+#              #
#    Updated: 2023/02/15 15:30:01 by maserrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ALIAS

CFLAGS = -Wall -Werror -Wextra -g
CC = gcc
RM = rm -fr
INC = -I ${LIBFT_PATH}/inc -I ./inc/
NAME = libftprintf.a
LIBFT_PATH = ./libft/
LIBFT = libft/libft.a

#COLOR

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#SRCS

PRE_SRC =	ft_printf.c\
			ft_printf_funct.c\
			ft_putunsigned.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_putnbr.c\
			ft_puthexa.c\
			ft_atoi_printf.c\

SRCS = $(addprefix src/, ${PRE_SRC})
OBJS = $(patsubst src%, obj%, $(SRCS:.c=.o))

#COMMANDES

all: obj ${NAME}

${NAME}:: ${LIBFT}

${NAME}:: ${OBJS}
	@echo "]"
	@ar rc ${NAME} ${OBJS}

${NAME}::
	@ranlib ${NAME}
	@echo "${GREEN}Printf done"

${LIBFT}:
	@make -sC ${LIBFT_PATH} all
	@cp ${LIBFT} ${NAME}

bonus: all

obj:
	@mkdir obj

obj/%.o: src/%.c PRINTF_functs
	@${CC} ${CFLAGS} ${INC} -o $@ -c $<
	@echo -n "-"

clean:
	@make -s -C ${LIBFT_PATH} fclean
	@${RM} obj
	@echo "${GREY}Cleaning Printf"

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY = all clean fclean re

all: obj ${NAME}

%functs:
	@echo -n "${YELLOW}[...] Compiling $@ ["

PRINT:
	@echo ${OBJS_BONUS}${PART_BONUS}
