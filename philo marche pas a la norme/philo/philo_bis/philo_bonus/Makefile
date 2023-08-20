NAME		:=	philo_bonus

CC			:=	clang -Wall -Wextra -Werror
#DEBUG_FLAGS	:=	-g -fsanitize=thread
FLAGS		:=	-lpthread -Llibft -lft

DIR_SRCS	:=	srcs
DIR_OBJS	:=	.objs
DIR_INCS	:=	include

LST_SRCS	:=	death.c \
				forks.c \
				init.c \
				main.c \
				process.c \
				utils.c
LST_OBJS	:=	$(LST_SRCS:.c=.o)
LST_INCS	:=	philosophers.h

SRCS		:=	$(addprefix $(DIR_SRCS)/, $(LST_SRCS))
OBJS		:=	$(addprefix $(DIR_OBJS)/, $(LST_OBJS))
INCS		:=	$(addprefix $(DIR_INCS)/, $(LST_INCS))

ERASE		:=	\033[2K\r
BLUE		:=	\033[34m
YELLOW		:=	\033[33m
GREEN		:=	\033[32m
END			:=	\033[0m

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c $(INCS) Makefile libft/libft.a
	mkdir -p $(DIR_OBJS)
	$(CC) -I $(DIR_INCS) -c $< -o $@
	printf "$(ERASE)$(BLUE) > Compilation :$(END) $<"

all:		libft $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) $(FLAGS) -o $@
	printf "$(ERASE)$(GREEN)$@ made\n$(END)"

libft:
	make -C libft

clean:
	printf "$(YELLOW)$(DIR_OBJS) removed$(END)\n"
	rm -rdf $(DIR_OBJS)
	printf "libft : "
	make clean -C libft

fclean:		clean
	printf "$(YELLOW)$(NAME) removed$(END)\n"
	rm -rf $(NAME) checker
	printf "libft : "
	make fclean -C libft

re:			fclean all

.PHONY:		all libft clean fclean re
.SILENT:
