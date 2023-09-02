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
#include <iomanip>
#include "contact.class.hpp"

contact::contact(void)
{
        return;
}

contact::~contact(void)
{
        return;
}
 
void	contact::init(void)
{
        long unsigned int     i;

	std::cout << "First name : ";
	std::getline (std::cin, _first_name);
        first_name = copyPrivateToPublic(_first_name, first_name);
        
        std::cout << "Last name : ";
	std::getline (std::cin, _last_name);
        last_name = copyPrivateToPublic(_last_name, last_name);
        
        std::cout << "Nickname : ";
	std::getline (std::cin, _nickname);
        nickname = copyPrivateToPublic(_nickname, nickname);
        
        std::cout << "Phone number : ";
	std::getline (std::cin, _phone_number);
        phone_number = copyPrivateToPublic(_phone_number, phone_number);

        std::cout << "Darkest secret : ";
	std::getline (std::cin, _darkest_secret);
        darkest_secret = copyPrivateToPublic(_darkest_secret, darkest_secret);

	return;
}

std::string    contact::copyPrivateToPublic(std::string str, std::string str2) 
{
        int     i;
        int     i2;

        i = 0;
        i2 = 0;
        str2 = "          ";
        if (str.length() < 10)
        {
                i2 = 10 - str.length();
                while (i2 < 10)
                        str2[i2++] = str[i++];
        }
        else
        {
                while (i < 9)
                {
                        str2[i] = str[i]; 
                        i++;
                }
                if (str.length() == 10)
                        str2[i] = str[i];
                else
                        str2[i] = '.';
        }
        return (str2);
}
