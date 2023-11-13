/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:25:44 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/13 08:02:54 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <stdexcept>

class BitcoinExchange
{
    private :

        BitcoinExchange(void);
        std::map<std::string, float>	_data;

    public :

        BitcoinExchange(std::ifstream &file, char **av);
        ~BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange & src);
        BitcoinExchange & operator=(const BitcoinExchange & rhs);

        void    fillMap(std::ifstream & file);
        void	fillInput(std::ifstream &inputs, char **av);
        void    findDate(std::string date, float value);
        void    verifyInput(std::string date, float value);
        void    printMap();

        class Exception : public std::exception
        {
            private :

                const char  *_msg;
            
            public :

                Exception(void) : _msg("error") {}
                Exception(const char *msg) : _msg(msg) {}
                const char* what() const throw()
                {
                    return this->_msg;
                }
        };
};
