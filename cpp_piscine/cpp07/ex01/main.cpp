/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:47:41 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/04 14:11:34 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void	iter(T *array, size_t len, void (*func)(T&))
{
    size_t i = -1;

    while(++i < len)
        func(array[i]);
}

template<typename T>
void	display(T & val)
{
    std::cout << "Variable value : " << val << std::endl;
}

int main( void ) 
{
    int array1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char array2[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    std::string array3[3] = {"toto", "tutu", "tata"};

    std::cout << "display int array :" << std::endl;
    ::iter<int>(array1, 10, &display);

    std::cout << "display char array :" << std::endl;
    ::iter<char>(array2, 10, &display);

    std::cout << "display string array :" << std::endl;
    ::iter<std::string>(array3, 3, &display);
    return 0;
}