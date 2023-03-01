SRC = ft_printf.c ft_printf_utils.c ft_printf_unsigned.c
OBJ = $(SRC:.c=.o)

CC = gcc
RM = rm
F = -Wall -Werror -Wextra

LIBFTPATH = libft/

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	cd $(LIBFTPATH); make
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

clean:
	cd $(LIBFTPATH); make clean
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
