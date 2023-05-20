############################################################
## ARGUMENTS

NAME		= so_long
BONUS		= so_long_bonus
CFLAGS		= -Wall -Werror -Wextra
CCFLAGS		= -lX11 -lXext -lm -lbsd
IFLAGS		= -I./include
CC		= clang

############################################################
## SOURCES

SRC		= src/so_long			\
		  src/ft_split			\
		  src/break_prog		\
		  src/check_map			\
		  src/check_move		\
		  src/check_arg			\
		  src/window			\
		  src/put_windows		\
		  src/player_gps		\
		  src/check_limits

SRC_BONUS	= src_bonus/so_long_bonus	\
		  src_bonus/check_arg_bonus	\
		  src_bonus/window_bonus	\
		  src_bonus/put_windows_bonus	\
		  src_bonus/player_gps_bonus	\
		  src_bonus/ft_split_bonus	\
		  src_bonus/ft_itoa_bonus	\
		  src_bonus/check_move_bonus	\
		  src_bonus/check_map_bonus	\
		  src_bonus/check_limits_bonus	\
		  src_bonus/break_prog_bonus

OBJ		= $(addsuffix .o, $(SRC))

OBJ_BONUS	= $(addsuffix .o, $(SRC_BONUS))

HEADER		= ./include/so_long.h

HEADER_BONUS	= ./include/so_long_bonus.h

############################################################
## RULES

all: ${NAME}

bonus: ${BONUS}

${NAME}: ${OBJ}
	make -C minilibx
	make -C printf
	${CC} ${CFLAGS} ${OBJ} printf/printf.a minilibx/libmlx.a ${CCFLAGS} -o ${NAME}

${BONUS}: ${OBJ_BONUS}
	make -C minilibx
	make -C printf
	${CC} ${CFLAGS} ${OBJ_BONUS} printf/printf.a minilibx/libmlx.a ${CCFLAGS} -o ${BONUS}

%.o: %.c ${HEADER} ${HEADER_BONUS}
	${CC} ${CFLAGS} ${IFLAGS} -c $< -o $@

clean:
	make clean -C minilibx
	make clean -C printf
	rm -f ${OBJ} ${OBJ_BONUS}

fclean: clean
#	make fclean -C minilibx
	make fclean -C printf
	rm -f ${NAME} ${BONUS}

re: fclean all

.PHONY:	all clean fclean re




