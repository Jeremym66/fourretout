/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:03:31 by jmetezea          #+#    #+#             */
/*   Updated: 2023/08/31 16:45:03 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "megaphone.class.hpp"

Megaphone::Megaphone(void) {

	std::cout << "constructor" << std::endl;
	return;
}

Megaphone::~Megaphone(void) {
	
	std::cout << "destructor" << std::endl;
	return;
}

Megaphone::up(char c) {

	this.a = std::toupper(c);
	std::cout << this.a;
}
