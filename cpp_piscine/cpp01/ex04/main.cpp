/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 07:38:46 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/03 11:15:05 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.Class.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "./Sed <filename> <string1> <string2>" << std::endl;
        std::cout << "<filename> must exist"<< std::endl;
        std::cout << "<string1> the character string we are looking for in the file" << std::endl;
        std::cout << "<string2> the character string that will replace <string1> in the file" << std::endl;
        return (EXIT_FAILURE);
    }
    Sed test(av[1], av[2], av[3]);
    
    if (test.check == 1)
        return (EXIT_FAILURE);
    test.create_file();
    
    return (EXIT_SUCCESS);
}