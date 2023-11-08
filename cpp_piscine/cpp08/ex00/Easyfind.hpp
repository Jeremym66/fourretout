/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:20:46 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/08 07:42:27 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <stdexcept>

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

template<typename T>
int	easyfind(T const & array, int val);