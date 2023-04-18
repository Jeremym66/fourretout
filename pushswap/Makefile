############################################################
## ARGUMENTS

NAME		= push_swap
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

OBJ		= $(addsuffix .o, $(SRC))

HEADERS		= ./include/pushswap.h

############################################################
## RULES

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${OBJ} -o ${NAME}

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} ${IFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re




