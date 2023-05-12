############################################################
## ARGUMENTS

NAME		= so_long
CFLAGS		= -Wall -Werror -Wextra
#CCFLAGS	= -lX11 -lXext -lmlx
#IFLAGS		= -I./include
CC		= clang
#MINILIBX	= minilibx/
#MINILIBXCC	= -I mlx -L lib/minilibx -lmlx
#OPENGL		= -framework OpenGL -framework AppKit

############################################################
## SOURCES

SRC		= src/so_long			\
		  src/ft_split			\
		  src/check_map			\
		  src/check_move		\
		  src/check_arg			\
		  src/window			\
		  src/put_windows		\
		  src/player_gps		\
		  src/check_limits

#SRC_BONUS	= srcs_bonus/check_arg		\

OBJ		= $(addsuffix .o, $(SRC))

#OBJ_BONUS	= $(addsuffix .o, $(SRC_BONUS))

#HEADERS		= /include/so_long.h
HEADER		= -I include

#HEADERS_BONUS	= /include/checker.h

############################################################
## RULES

all: ${NAME}

bonus: ${BONUS}

${NAME}: ${OBJ}
	make -C minilibx
	${CC} ${CFLAGS} ${OBJ} minilibx/libmlx.a -lXext -lX11 -lm -lbsd -o ${NAME}

${BONUS}: ${OBJ_BONUS}
	make -C minilibx
	${CC} ${CFLAGS} ${OBJ_BONUS} minilibx/libmlx.a -lXext -lX11 -lm -lbsd -o ${BONUS}

%.o: %.c
	${CC} ${CFLAGS} ${HEADER} -c $< -o $@

clean:
	make clean -C minilibx
	rm -f ${OBJ} ${OBJ_BONUS}

fclean: clean
#	make fclean -C minilibx
	rm -f ${NAME} ${BONUS}

re: fclean all

.PHONY:	all clean fclean re




