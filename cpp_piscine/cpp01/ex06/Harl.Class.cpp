/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.Class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:13:41 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/08 09:47:20 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.Class.hpp"

Harl::Harl()
{
    this->_level_mess[0] = "DEBUG";
	this->_ptr_fonction[0] = &Harl::debug;
	this->_level_mess[1] = "INFO";
	this->_ptr_fonction[1] = &Harl::info;
	this->_level_mess[2] = "WARNING";
	this->_ptr_fonction[2] = &Harl::warning;
	this->_level_mess[3] = "ERROR";
	this->_ptr_fonction[3] = &Harl::error;
}

Harl::~Harl()
{}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my " << std::endl;
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon " << std::endl;
	std::cout << "costs more money. You didn’t put enough bacon in my burger! If " << std::endl;
	std::cout << "you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra " << std::endl;
	std::cout << "bacon for free. I’ve been coming for years whereas you started " << std::endl;
	std::cout << "working here since last month." << std::endl << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain(std::string level) 
{
    void	(Harl::*fctPTR)(void) = nullptr;

    int			i = 0;
	while (i < 4)
	{
		if (level == this->_level_mess[i])
		{
			fctPTR = this->_ptr_fonction[i];
			break;
		}
		i++;
	}
	
    if (fctPTR != nullptr)
    {
        (this->*fctPTR)();
    }
    else
    {
        std::cout << "Unknown level: " << level << std::endl;
    }
}





