/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:21:44 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/14 13:52:38 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	std::cout << "*****************************" << std::endl;
    std::cout << "**       RPN's Test        **" << std::endl;
    std::cout << "*****************************" << std::endl << std::endl;
	try
	{
		if (argc != 2)
		{
			std::cout << "Usage : ./RPN \"<0 - 9> <0 - 9> <sign>\"" << std::endl;
			return 1;
		}
		RPN * rpn = new RPN;
		rpn->fillStack(argv[1]);
		delete rpn;
	}
	catch(std::exception &e)
    {
		std::cout << e.what() << std::endl;
    }
	return 0;
}
