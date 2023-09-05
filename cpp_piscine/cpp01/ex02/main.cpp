/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:07:55 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/01 09:00:53 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "adresse de la string : " << &str << std::endl;
    std::cout << "adresse stockee dans stringPTR : " << stringPTR << std::endl;
    std::cout << "adresse stockee dans stringREF : " << &stringREF << std::endl;
    std::cout << std::endl;

    std::cout << "valeur de la string : " << str << std::endl;
    std::cout << "valeur pointe par stringPTR : " << *stringPTR << std::endl;
    std::cout << "valeur pointe par stringREF : " << stringREF << std::endl;

	return (0);
}