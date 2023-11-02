/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <kaly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:08:22 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/02 17:52:05 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.class.hpp"

bool isInt(std::string &str)
{
    if(((str[0] == '+' || str[0] == '-') && str.length() <= 1)
            || (!isdigit(str[0]) && str[0] != '-' && str[0] != '+'))
        return false;

    for(size_t i = 1; i < str.length(); i++)
    {
        if(!isdigit(str[i]))
            return false;
    }
    if (str.length() > 15)
        return false;
    long long number = std::stoll(str);
    if (number >= INT_MIN && number <= INT_MAX)
        return true;
    return false;
}

bool isChar(std::string &str)
{
    if (str.length() == 1 && std::isprint(str[0]))
        return true;
    return false;
}

bool isFloat(std::string &str)
{
    if(((str[0] == '+' || str[0] == '-') && str.length() <= 1)
        || (!isdigit(str[0]) && str[0] != '-' && str[0] != '+'))
    return false;

    bool pointcount = false;

    for(size_t i = 1; i < str.length(); i++)
    {
        if(!isdigit(str[i]))
        {
            if(str.length() - 1 == i)
            {
                if(str[i] == 'f' && pointcount == true)
                    return true;
                return false;
            }
            if(str[i] == '.')
            {
                if(pointcount)
                    return false;
                pointcount = true;
            }
            else
                return false;
        }
    }
    return false;
}

bool isDouble(std::string &str)
{
    if(((str[0] == '+' || str[0] == '-') && str.length() <= 1)
        || (!isdigit(str[0]) && str[0] != '-' && str[0] != '+'))
    return false;

    bool pointcount = false;

    for(size_t i = 1; i < str.length(); i++)
    {
        if(!isdigit(str[i]))
        {
            if(str[i] == '.')
            {
                if(pointcount)
                    return false;
                pointcount = true;
            }
            else
                return false;
        }
    }
    return true;
}

bool floatIsParticular(std::string &str)
{
    int i = 0;
    while (str[i] && str[i] != '.')
        i++;
    if (str[i + 1] == 'f')
        return false;
    i++;
    while (str[i] && str[i] == '0')
        i++;
    if (i == str.length())
        return false;
    return true;
}

bool doubleIsParticular(std::string &str)
{
    int i = 0;
    while (str[i] && str[i] != '.')
        i++;
    if (i + 1 == str.length())
        return true;
	i++;
    while (str[i] && str[i] == '0')
        i++;
    if (i == str.length())
        return true;
    return false;
}

int isOthers(std::string &str)
{
    if(str == "nanf" || str == "nan")
        return 1;
    if(str == "-inff" || str == "-inf")
        return 2;
    if(str == "+inff" || str == "+inf")
        return 3;
    return 0;
}

static void    checkInput(std::string str)
{
	if (isChar(str) == true)
    {
        int i = str[0] - 48;
        std::cout << "char: ";
        if(i < 32 || i > 126)
            std::cout << "No printable char\n";
		else
            std::cout << static_cast<char>(str[0]) << std::endl;
        if(i < 32)
        {
            std::cout << "int: " << i << std::endl;
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(str[0]) - 48 << "f" << std::endl;
            std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(str[0]) - 48 << std::endl;
        }
        else
        {
            std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(str[0]) << "f" << std::endl;
            std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(str[0]) << std::endl;
        }
    }
	else if (isInt(str) == true)
    {
        int i = std::stoi(str);

		std::cout << "i: " << i << std::endl;

        std::cout << "char: ";
        if(i > 255 || i < 0)
            std::cout << "Overflow of ascii table\n";
        else if (i < 32 || i > 126)
            std::cout << "Non displayable\n";
        else
            std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(i) << std::endl;
        std::cout << "float: " << str << ".0f" << std::endl;
        std::cout << "double: " << str << ".0" << std::endl;
    }
    
    else if (isFloat(str) == true)
    {
        double i = std::stod(str);
        int y = str.size() - 2;
        std::string str2;

        if (str[y] == '.')
            str2 = str.substr(0, str.size() - 2);
        else
            str2 = str.substr(0, str.size() - 1);

        std::cout << "char: ";
        if(i > 255 || i < 0)
            std::cout << "Overflow of ascii table\n";
        else if (i < 32 || i > 126)
            std::cout << "Non displayable\n";
        else
            std::cout << "'" << static_cast<char>(i) << "'" << std::endl;

        if (i > INT_MAX || i < INT_MIN)
            std::cout << "int: Overflow (Max / Min Int)" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(i) << std::endl;
        std::cout << "float: " << str << std::endl; 
        if (floatIsParticular(str) == true)
            std::cout << "double: " << str2 << std::endl;
        else
            std::cout << "double: " << str2 << ".0" << std::endl;
    }
    else if (isDouble(str) == true)
    {
        double i = std::stod(str);

        std::cout << "char: ";
        if(i > 255 || i < 0)
            std::cout << "Overflow of ascii table\n";
        else if (i < 32 || i > 126)
            std::cout << "Non displayable\n";
        else
            std::cout << "'" << static_cast<char>(i) << "'" << std::endl;

        if (i > INT_MAX || i < INT_MIN)
            std::cout << "int: Overflow (Max / Min Int)" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(i) << std::endl;
        if (doubleIsParticular(str) == true)
        {
            std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(i) << "f" << std::endl;   
            std::cout << "double: " << i << std::endl;
        }
        else
        {
            std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;   
            std::cout << "double: " << i << std::endl;
        }
    }
    else if (isOthers(str) == 1)
    {
        std::cout << "test other 1" << std::endl;
        double i = std::stod(str);

        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << std::endl;
        std::cout << "double: " << static_cast<double>(i) << std::endl;
    }
    else if (isOthers(str) == 2)
    {   
        std::cout << "test other 2" << std::endl;
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << __FLT_MIN__ << "f" << std::endl;
        std::cout << "double: " << __DBL_MIN__ << std::endl;
	}
	else if (isOthers(str) == 3)
    {   
        std::cout << "test other 2" << std::endl;
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << __FLT_MAX__ << "f" << std::endl;
        std::cout << "double: " << __DBL_MAX__ << std::endl;
	}
	else
    {
        std::cout << "test other" << std::endl;
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: imposssible" << std::endl;
        std::cout << "double: impossible" << std::endl; 
    }
}

void	ScalarConverter::Convert(std::string str)
{
	checkInput(str);
}