/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:03:31 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/01 08:00:36 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "megaphone.class.hpp"

Megaphone::Megaphone(void) {

	//std::cout << "constructor" << std::endl;
	return;
}

Megaphone::~Megaphone(void) {
	
	//std::cout << "destructor" << std::endl;
	return;
}

void	Megaphone::up(char *str) {

	int	i;

	i = -1;
	while(str[++i])
	{
		this->a = std::toupper(str[i]);
		std::cout << this->a;
	}
}
