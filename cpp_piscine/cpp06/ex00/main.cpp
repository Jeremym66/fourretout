/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <kaly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:03:24 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/02 17:50:19 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.class.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage : ./convert <to_convert>" << std::endl;
        return 0;
    }
    std::string str(argv[1]);
    if (str.empty())
    {
        std::cerr << "The thing you want to convert don't exist!" << std::endl;
        return 0;
    }
    ScalarConverter::Convert(str);
}
