# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 17:57:52 by kaly              #+#    #+#              #
#    Updated: 2023/10/18 15:47:25 by jmetezea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = animal

SRC = 	main.cpp animal.class.cpp cat.class.cpp dog.class.cpp wronganimal.class.cpp \
		wrongcat.class.cpp brain.class.cpp

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

