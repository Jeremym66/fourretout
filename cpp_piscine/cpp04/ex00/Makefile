# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaly <kaly@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 17:57:52 by kaly              #+#    #+#              #
#    Updated: 2023/10/17 18:00:01 by kaly             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = animals

SRC = 	main.cpp animals.class.cpp

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

