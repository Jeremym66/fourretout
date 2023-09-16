# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 14:21:35 by sdestann          #+#    #+#              #
#    Updated: 2023/09/16 18:07:31 by jmetezea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### MISC ###

NAME = cub3d

HEADER_SRCS = cub3d.h
HEADER_DIR = includes/
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

SRCS_DIR = srcs/
SRCS =	window.c		\
		main.c			\
		maps.c			\
		break_prog.c	\
		check_arg.c 	\
		error.c			\
		print.c			\
		utils.c			\
		verif_map.c		\
		verif_player.c	

OBJDIR = objs

SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))
OBJ_SRCS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

CFLAGS		= -Wall -Wextra -Werror

CC			= gcc -g
LIBFT		= libft
LIBMLX		= libmlx
LIBFT_DIR	= libft/

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

### RULES ###

all: ${NAME}

%.o: %.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJ_SRCS}
	@echo $(G)Creating libft files$(X)
	@make -s -C $(LIBFT)
	@make -s -C $(LIBMLX)
	@$(CC) $(OBJ_SRCS) -L$(LIBFT) ./libmlx/*.a -lXext -lX11 -lm -lft -o $(NAME)
	@echo $(G)Project CUB3D by JMETEZEA and SDESTANN successfully compiled${X}

$(OBJDIR)/%.o: $(SRCS_DIR)%.c $(HEADER) Makefile
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

norminette:
	@echo ${G}Norminette sources files${X}
	@norminette ./srcs
	@echo ${G}Norminette includes files${X}
	@norminette ./includes/
	@echo ${G}Norminette libft files${X}
	@norminette ./libft/

clean:
	@echo ${R}Cleaning CUB3D ${G}[${OBJDIR}]...${X}
	@make clean -s -C $(LIBFT)
	@/bin/rm -Rf ${OBJDIR}

fclean:
	@echo ${R}FCleaning CUB3D ${G}[${NAME}]...${X}
	@make fclean -s -C $(LIBFT)
	@/bin/rm -Rf ${OBJDIR}
	@/bin/rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
