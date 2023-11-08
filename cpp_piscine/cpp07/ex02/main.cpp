/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:13:55 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/07 08:16:12 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.cpp"

int	main()
{
	Array<int>			intArray;
	Array<int>			copy(5);
	Array<std::string>	strArray(5);
    int i = -1;

	while (++i < 5)
    {
		copy[i] = rand() % 100;
        std::cout << "in Array [" << i << "] the value is : " << copy[i] << std::endl;
    }

	std::cout << "intArray size: " << intArray.getsize() << std::endl;
	std::cout << "strArray size: " << strArray.getsize() << std::endl;
	std::cout << "copy size: " << intArray.getsize() << std::endl;

	std::cout << "\nLet's assign copy to intArray..." << std::endl;
	intArray = copy;
	std::cout << intArray << std::endl;

	std::cout << "\nLet's write the strArray with strings..." << std::endl;
	strArray[0] = "Nours";
	strArray[1] = "Eat";
	strArray[2] = "Lot";
	strArray[3] = "Of";
	strArray[4] = "Cupcakes";
	std::cout << strArray << std::endl;

	std::cout << "\nLet's try getting elems out of intArray size" <<std::endl;
	try
	{
		std::cout << intArray[59] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "59: " << e.what() << std::endl;
	}

	try
	{
		std::cout << intArray[-3] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "-3: " << e.what() << std::endl;
	}

	return (0);
}