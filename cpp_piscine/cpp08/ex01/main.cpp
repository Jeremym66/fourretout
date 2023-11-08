/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:21:44 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/08 14:40:05 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << "*****************************" << std::endl;
    std::cout << "**       First's Test      **" << std::endl;
    std::cout << "*****************************" << std::endl << std::endl;
	try
	{
		Span sp = Span(10000);
		int nb;

		srand(time(NULL));
		for (unsigned int i = 0; i != 10000; i++)
		{
			if (i % 2)
				nb = rand() % 100000;
			else
				nb = (rand() % 100000) * (-1);
			sp.addNumber(nb);
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e)
    {
		std::cout << e.what() << std::endl << std::endl;
    }
	
    std::cout << "*****************************" << std::endl;
    std::cout << "**       Second's Test     **" << std::endl;
    std::cout << "*****************************" << std::endl << std::endl;
	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(12);
	}
	catch(std::exception &e)
    {
		std::cout << e.what() << std::endl << std::endl;
    }

    std::cout << "*****************************" << std::endl;
    std::cout << "**       Third's Test      **" << std::endl;
    std::cout << "*****************************" << std::endl << std::endl;
	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e)
    {
		std::cout << e.what() << std::endl << std::endl;
    }

	std::cout << "*****************************" << std::endl;
    std::cout << "**       Fourth's Test     **" << std::endl;
    std::cout << "*****************************" << std::endl << std::endl;
	try
	{
		Span sp = Span(2);

		sp.addNumber(INT_MAX);
		sp.addNumber(INT_MIN);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e)
    {
		std::cout << e.what() << std::endl << std::endl;
    }

	std::cout << "*****************************" << std::endl;
    std::cout << "**       Last's Test       **" << std::endl;
    std::cout << "*****************************" << std::endl << std::endl;
	try
	{
		Span sp = Span(50);

		sp.addManyNumbers(60);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e)
    {
		std::cout << e.what() << std::endl << std::endl;
    }
	return 0;
}
