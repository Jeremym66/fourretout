/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:07:55 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/01 09:00:53 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "phonebook.class.hpp"
#include "contact.class.hpp"

int	main(int ac, char **av)
{
	phonebook myphonebook;
	contact newcontact;
	std::string	command;

	while (1)
	{
		std::cout << "Command ? : ";
		std::getline (std::cin, command);
		if (command == "EXIT" || command == "exit")
			break;
		else if (command == "ADD" || command == "add")
		{
			std::cout << std::endl;
			newcontact.init();
			myphonebook.addcontact(&newcontact);
		}
		else if (command == "LIST" || command == "list")
			myphonebook.showcontacts();
		else if (command == "SEARCH" || command == "search")
			myphonebook.showonecontact();
		std::cout << std::endl;
	}
	return 0;
}
