# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/31 15:54:20 by jmetezea          #+#    #+#              #
#    Updated: 2023/10/04 02:11:27 by jmetezea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed

SRC = 	main.cpp Fixed.class.cpp

FLAG = -Wall -Werror -Wextra -std=c++98

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAG) -o $(NAME) $(OBJ)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: clean all

