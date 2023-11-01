/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:00:57 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/01 12:52:21 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

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
    // }
    // catch (err)
    // {
    //     return false;
    // }
    return false;
}

bool isChar(std::string &str)
{
    if (str[0] == '\n')
        std::cout << "test" << std::endl;
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
    if (i == str.length())
        return true;
    i++;
    while (str[i] && str[i] == '0')
        i++;
    if (i == str.length())
        return false;
    return true;
}

int isOthers(std::string &str)
{
    if(str == "nanf" || str == "-inff" || str == "+inff")
        return 1; // Is float
    if(str == "nan" || str == "-inf" || str == "+inf")
        return 2; // Is double
    return 0; // Is unknown 
}