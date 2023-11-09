/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:25:44 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/09 14:25:48 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <climits>

class Span
{
    private :

        Span(void);

        std::vector<int>	_vec;
        unsigned int    _size_max;
        unsigned int    _size;


    public :

        ~Span(void);
        Span(unsigned int N);
        Span(const Span & src);
        Span & operator=(const Span & rhs);

        void    addNumber(int nb);
        void	addManyNumbers(int n);
        unsigned int     shortestSpan(void);
        unsigned int     longestSpan(void);

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
