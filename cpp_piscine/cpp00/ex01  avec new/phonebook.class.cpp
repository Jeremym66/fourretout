/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:03:31 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/01 08:40:23 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "phonebook.class.hpp"

phonebook::phonebook() : nb_contact(0), idx(0)
{
	std::cout << "your phonebook is ready" << std::endl << std::endl;
    std::cout << "if you want add a new contact enter : ADD" << std::endl;
    std::cout << "show contact : SEARCH" << std::endl;
    std::cout << "and if you want to exit : EXIT" << std::endl << std::endl;
	return;
}

phonebook::~phonebook(void)
{	
	if (nb_contact > 7)
		nb_contact = 7;
    for (int i = 0; i <= nb_contact; i++)
    {
        delete contacts[i];
    }
	return;
}

void phonebook::addcontact(contact *newcontact)
{
	if (nb_contact > 7)
		delete contacts[nb_contact % 8];
    contacts[nb_contact % 8] = new contact(*newcontact);
	nb_contact++;
    std::cout << "Contact added to directory." << std::endl;
}

void phonebook::showcontacts()
{
	if (nb_contact == 0)
		std::cout << std::endl << "My Phonebook is empty !" << std::endl;
	else
	{
		std::cout << std::endl << "My Phonebook :" << std::endl << std::endl;
		std::cout << "----------------------------------------------" << std::endl;
		while (++idx < 9 && idx - 1 < nb_contact)
		{
			std::cout << "| " << contacts[idx - 1]->first_name << "|";
			std::cout << contacts[idx - 1]->last_name << "|";
			std::cout << contacts[idx - 1]->nickname << "|";
			std::cout << contacts[idx - 1]->phone_number << "|" << std::endl;
		}
		std::cout << "----------------------------------------------" << std::endl;
		idx = 0;
	}
}

void phonebook::showonecontact()
{
	if (nb_contact == 0)
		std::cout << std::endl << "My Phonebook is empty !" << std::endl;
	else
	{
		while (true)
		{
			std::cout << std::endl << "Contact number (1-8): ";
			std::cin >> idx;
			if (std::cin.fail() || idx < 1 || idx > 8)
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Invalid input. Please enter a number between 1 and 8." << std::endl;
			}
			else
			{
				std::cin.ignore(1000, '\n');
				break;
			}
		}

		if (idx > nb_contact && idx >= 1 && idx <= 8 )
			std::cout << std::endl << "Wrong number : Just " << nb_contact << " contact existing !" << std::endl;
		else
		{
			std::cout << std::endl << "----------------------------------------------" << std::endl;
			std::cout << "| " << contacts[idx - 1]->first_name << "|";
			std::cout << contacts[idx - 1]->last_name << "|";
			std::cout << contacts[idx - 1]->nickname << "|";
			std::cout << contacts[idx - 1]->phone_number << "|" << std::endl;
			std::cout << "----------------------------------------------" << std::endl;
		}
		idx = 0;
	}
	return;
}