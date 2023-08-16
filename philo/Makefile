# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 14:21:35 by sdestann          #+#    #+#              #
#    Updated: 2023/08/10 14:36:16 by sdestann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### MISC ###

NAME = philo

HEADER_SRCS = philo.h
HEADER_DIR = includes/
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

SRCS_DIR = srcs/
SRCS =	main.c		\
		utils.c

OBJDIR = objs

SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))
OBJ_SRCS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

CFLAGS		= -Wall -Wextra -Werror

CC			= gcc -g ##-fsanitize=thread
##LIBFT		= libft
##LFTA 		= ./libft/libft.a

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
##	@echo $(G)Creating libft files$(X)
	@$(CC) $(OBJ_SRCS) -pthread -o $(NAME)
	@echo $(G)Project Philosophers by JMETEZEA successfully compiled${X}

$(OBJDIR)/%.o: $(SRCS_DIR)%.c $(HEADER) Makefile
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

clean:
	@echo ${R}Cleaning Philosophers ${G}[${OBJDIR}]...${X}
	@/bin/rm -Rf ${OBJDIR}

fclean:
	@echo ${R}FCleaning Philosophers ${G}[${NAME}]...${X}
	@/bin/rm -Rf ${OBJDIR}
	@/bin/rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re