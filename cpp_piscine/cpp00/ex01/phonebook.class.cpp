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

phonebook::phonebook() : _nb_contact(0)
{
	std::cout << "constructor de phonebook" << std::endl;
	std::cout << "nb de contact : " << this->_nb_contact << std::endl;
	return;
}

phonebook::~phonebook(void)
{	
	std::cout << "destructor de phonebook" << std::endl;
	return;
}

void phonebook::addcontact(contact &newcontact)
{
    if (_nb_contact == 8)
		_nb_contact = 0
    contacts[_nb_contact] = newContact; // Ajoutez le nouveau contact au tableau
    _nb_contact++; // Incrémente le nombre de contacts
    std::cout << "Contact ajouté au répertoire." << std::endl;
}