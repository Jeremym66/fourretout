/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:21:44 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/08 08:00:27 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.tpp"

int	main() 
{
	std::list<int>	lst;
	int				ret;
	bool			exception_caught = true;

    std::cout << "*****************************" << std::endl;
    std::cout << "**        First Test       **" << std::endl;
    std::cout << "*****************************" << std::endl << std::endl;

	lst.push_back(5);
	lst.push_back(6);
	lst.push_back(32);
	lst.push_back(15);

	try 
    {
		ret = easyfind(lst, 33);
		exception_caught = false;
	}
	catch(std::exception &e)
    {
		std::cout << e.what() << std::endl << std::endl;
    }
    
	if (exception_caught == false)
		std::cout << "Value found : " << ret << std::endl << std::endl;

    std::cout << "*****************************" << std::endl;
    std::cout << "**        Second Test      **" << std::endl;
    std::cout << "*****************************" << std::endl << std::endl;

	lst.push_back(16);
	lst.push_back(33);
	lst.push_back(12);

	try 
    {
		ret = easyfind(lst, 33);
		exception_caught = false;
	}
	catch(std::exception &e)
    {
		std::cout << e.what() << std::endl << std::endl;
    }
    
	if (exception_caught == false)
		std::cout << "Value found : " << ret << "." << std::endl << std::endl;

	return 0;
}