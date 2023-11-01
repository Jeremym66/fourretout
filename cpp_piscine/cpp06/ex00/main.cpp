/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:03:24 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/01 15:21:33 by jmetezea         ###   ########.fr       */
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

// void    conv(std::string &str)
// {
//     if (isChar(str) == true)
//     {
//         int i = str[0] - 48;
//         std::cout << "char: ";
//         if(i < 32 || i > 126)
//             std::cout << "No printable char\n";
//         else
//             std::cout << static_cast<char>(str[0]) << std::endl;
//         if(i < 32)
//         {
//             std::cout << "int: " << i << std::endl;
//             std::cout << "float: " << static_cast<float>(str[0]) - 48 << ".0f" << std::endl;
//             std::cout << "double: " << static_cast<double>(str[0]) - 48 << ".0"<< std::endl;
//         }
//         else
//         {
//             std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
//             std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
//             std::cout << "double: " << static_cast<double>(str[0]) << ".0"<< std::endl;
//         }
//     }
//     else if (isInt(str) == true)
//     {
//         double i = std::stod(str);

//         std::cout << "char: ";
//         if(i > 255 || i < 0)
//             std::cout << "Overflow of ascii table\n";
//         else if (i < 32 || i > 126)
//             std::cout << "Non displayable\n";
//         else
//             std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
//         std::cout << "int: " << static_cast<int>(i) << std::endl;
//         std::cout << "float: " << str << ".0f" << std::endl;
//         std::cout << "double: " << str << ".0" << std::endl;
//     }
//     else if (isFloat(str) == true)
//     {
//         double i = std::stod(str);
//         int y = str.size() - 2;
//         std::string str2;
//         if (str[y] == '.')
//             str2 = str.substr(0, str.size() - 2);
//         else
//             str2 = str.substr(0, str.size() - 1);

//         std::cout << "char: ";
//         if(i > 255 || i < 0)
//             std::cout << "Overflow of ascii table\n";
//         else if (i < 32 || i > 126)
//             std::cout << "Non displayable\n";
//         else
//             std::cout << static_cast<char>(i) << std::endl;

//         if (i > INT_MAX || i < INT_MIN)
//             std::cout << "int: Overflow (Max / Min Int)" << std::endl;
//         else
//             std::cout << "int: " << static_cast<int>(i) << std::endl;
//         std::cout << "float: " << str << std::endl; 
//         if (floatIsParticular(str) == true)
//             std::cout << "double: " << str2 << std::endl;
//         else
//             std::cout << "double: " << str2 << ".0" << std::endl;
//     }
//     else if (isDouble(str) == true)
//     {
//         std::cout << "test double" << std::endl;

//         double i = std::stod(str);

//         std::cout << "char: ";
//         if(i > 255 || i < 0)
//             std::cout << "Overflow of ascii table\n";
//         else if (i < 32 || i > 126)
//             std::cout << "Non displayable\n";
//         else
//             std::cout << static_cast<char>(i) << std::endl;

//         if (i > INT_MAX || i < INT_MIN)
//             std::cout << "int: Overflow (Max / Min Int)" << std::endl;
//         else
//             std::cout << "int: " << static_cast<int>(i) << std::endl;
//         if (doubleIsParticular(str) == true)
//         {
//             std::cout << "float: " << static_cast<float>(i) << std::endl;   
//             std::cout << "double: " << i << std::endl;
//         }
//         else
//         {
//             std::cout << "float: " << static_cast<float>(i) << std::endl;   
//             std::cout << "double: " << i << std::endl;
//         }
//     }
//     else if (isOthers(str) == 1)
//     {
//         std::cout << "test other 1" << std::endl;
//         double i = std::stod(str);

//         std::cout << "char: impossible" << std::endl;
//         std::cout << "int: impossible" << std::endl;
//         std::cout << "float: " << str << std::endl;
//         std::cout << "double: " << static_cast<double>(i) << std::endl;
//     }
//     else if (isOthers(str) == 2)
//     {   
//         std::cout << "test other 2" << std::endl;
//         std::cout << "char: impossible" << std::endl;
//         std::cout << "int: impossible" << std::endl;
//         std::cout << "float: " << str << "f" << std::endl;
//         std::cout << "double: " << str << std::endl;
//     }
//     else
//     {
//         std::cout << "test other" << std::endl;
//         std::cout << "char: impossible" << std::endl;
//         std::cout << "int: impossible" << std::endl;
//         std::cout << "float: imposssible" << std::endl;
//         std::cout << "double: impossible" << std::endl; 
//     }
// }


