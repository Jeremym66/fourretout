# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/31 15:54:20 by jmetezea          #+#    #+#              #
#    Updated: 2023/09/01 08:55:23 by jmetezea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Walking_Dead

SRC = 	main.cpp Weapon.class.cpp HumanA.class.cpp HumanB.class.cpp

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

