############################################################
## ARGUMENTS

NAME		= so_long
BONUS		= checker
CFLAGS		= -Wall -Werror -Wextra -g
CCFLAGS		= -lX11 -lXext -lmlx
IFLAGS		= -I./include
CC		= clang
MINILIBX	= lib/minilibx/
MINILIBXCC	= -I mlx -L lib/minilibx -lmlx
OPENGL		= -framework OpenGL -framework AppKit

############################################################
## SOURCES

SRC		= srcs/main

SRC_BONUS	= srcs_bonus/check_arg		\

OBJ		= $(addsuffix .o, $(SRC))

OBJ_BONUS	= $(addsuffix .o, $(SRC_BONUS))

HEADERS	= ./include/so_long.h
#HEADER		= -I include

HEADERS_BONUS	= ./include/checker.h

############################################################
## RULES

all: ${NAME}

bonus: ${BONUS}

${NAME}: ${OBJ}
	make -s -C $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJ) $(HEADER) $(MINILIBXCC) -o $(NAME)
#	${CC} ${OBJ} -o ${NAME}

${BONUS}: ${OBJ_BONUS}
	${CC} ${OBJ_BONUS} -o ${BONUS}

%.o: %.c
	${CC} ${CFLAGS} ${HEADER} -c $< -o $@

clean:
	rm -f ${OBJ} ${OBJ_BONUS}

fclean: clean
	rm -f ${NAME} ${BONUS}

re: fclean all

.PHONY:	all clean fclean re




