/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 08:40:37 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/01 08:54:11 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "contact.class.hpp"

contact::contact(void)
{
        std::cout << "constructor de contact" << std::endl << std::endl;
        std::cout << "your phonebook is ready" << std::endl << std::endl;
        std::cout << "if you want add a new contact enter : ADD" << std::endl;
        std::cout << "show contact : SEARCH" << std::endl;
        std::cout << "and if you want to exit : EXIT" << std::endl << std::endl;
        return;
}

contact::~contact(void)
{
        std::cout << "destructor de contact" << std::endl;
        return;
}
 
void	contact::init(void)
{
	std::cout << "First name : ";
	std::getline (std::cin, this->_first_name);
	std::cout << "the first name : [" << this->_first_name << "]" << std::endl;
        
        std::cout << "Last name : ";
	std::getline (std::cin, this->_last_name);
	std::cout << "Last name : [" << this->_last_name << "]" << std::endl;
        
        std::cout << "Nickname : ";
	std::getline (std::cin, this->_nickname);
	std::cout << "Nickname : [" << this->_nickname << "]" << std::endl;
        
        std::cout << "Phone number : ";
	std::getline (std::cin, this->_phone_number);
	std::cout << "Phone number : [" << this->_phone_number << "]" << std::endl;

        std::cout << "Darkest secret : ";
	std::getline (std::cin, this->_darkest_secret);
	std::cout << "Darkest secret : [" << this->_darkest_secret << "]" << std::endl;

        std::cout << "The contact is created" << std::endl << std::endl;

	return;
}

