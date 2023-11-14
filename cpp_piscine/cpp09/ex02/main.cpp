/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:05:53 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/14 10:26:34 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	std::cout << "*****************************" << std::endl;
    std::cout << "**     PmergeMe's Test     **" << std::endl;
    std::cout << "*****************************" << std::endl << std::endl;
	try
	{
		if (argc <= 2)
		{
			std::cout << "Usage :" << argv[0] << " <list of at least 2 positive ints to sort>" << std::endl;
			return 1;
		}
		PmergeMe merge(argc, argv);
	}
	catch(std::exception &e)
    {
		std::cout << e.what() << std::endl;
    }
	return 0;
}
