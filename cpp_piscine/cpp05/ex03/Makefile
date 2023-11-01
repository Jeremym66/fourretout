# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 17:57:52 by kaly              #+#    #+#              #
#    Updated: 2023/10/31 07:57:59 by jmetezea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = bureaucrat

SRC = 	main.cpp Bureaucrat.class.cpp AForm.class.cpp ShrubberyCreationForm.class.cpp \
		RobotomyRequestForm.class.cpp PresidentialPardonForm.class.cpp Intern.class.cpp

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