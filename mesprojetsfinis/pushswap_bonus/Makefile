############################################################
## ARGUMENTS

NAME		= push_swap
BONUS		= checker
CFLAGS		= -Wall -Werror -Wextra
IFLAGS		= -I./include
CC		= gcc

############################################################
## SOURCES

SRC		= srcs/check_sort	\
		  srcs/ft_atoi		\
		  srcs/gps		\
		  srcs/push		\
		  srcs/pushswap		\
		  srcs/pushswap_utils	\
		  srcs/rotate		\
		  srcs/rrotate		\
		  srcs/sort		\
		  srcs/sort3		\
		  srcs/sort_bis		\
		  srcs/swap		

SRC_BONUS	= srcs_bonus/check_arg		\
		  srcs_bonus/checker		\
		  srcs_bonus/check_sort		\
		  srcs_bonus/ft_atoi		\
		  srcs_bonus/ft_strcmp		\
		  srcs_bonus/get_next_line	\
		  srcs_bonus/get_next_line_utils\
		  srcs_bonus/gps		\
		  srcs_bonus/push		\
		  srcs_bonus/pushswap_utils	\
		  srcs_bonus/rotate		\
		  srcs_bonus/rrotate		\
		  srcs_bonus/swap		

OBJ		= $(addsuffix .o, $(SRC))

OBJ_BONUS	= $(addsuffix .o, $(SRC_BONUS))

HEADERS		= ./include/pushswap.h

HEADERS_BONUS	= ./include/checker.h

############################################################
## RULES

all: ${NAME} ${BONUS}

bonus: ${BONUS}

${NAME}: ${OBJ}
	${CC} ${OBJ} -o ${NAME}

${BONUS}: ${OBJ_BONUS}
	${CC} ${OBJ_BONUS} -o ${BONUS}

%.o: %.c ${HEADERS} ${HEADERS_BONUS}
	${CC} ${CFLAGS} ${IFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ} ${OBJ_BONUS}

fclean: clean
	rm -f ${NAME} ${BONUS}

re: fclean all

.PHONY:	all clean fclean re




