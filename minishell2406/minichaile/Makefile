# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 09:23:59 by aperrein          #+#    #+#              #
#    Updated: 2023/07/04 14:24:11 by vgiraudo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

LIBFT = 	libft/libft.a

L = 		libft/

OBJ_DIR =	OBJ/

SRC_DIR =	SRC/

SRC	=	main.c pwd.c msh_executer.c msh_loop.c signal.c \
		exit.c env.c unset.c export_bis.c export.c \
		cd.c exec.c cmd.c redirect.c redirect_bis.c path.c \
		parse.c parse_space.c parse_split.c utils_parser.c \
		quote.c echo.c parse_utils.c

OBJ	=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

RM	=	rm -f

CFLAGS	=	-Wall -Werror -Wextra

all     :       $(OBJ_DIR) $(NAME)
	
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
		gcc $(CFLAGS) -g -c $< -o $@

$(OBJ_DIR) :
#		@./libft/swaps
		mkdir $(OBJ_DIR)

$(NAME)	:	$(OBJ) $(L)
		make -s -C libft/
		gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) -lreadline

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re 	:	fclean all
