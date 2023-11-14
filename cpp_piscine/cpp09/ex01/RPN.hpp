/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:36:46 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/14 13:44:43 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdexcept>
#include <stack>

class RPN
{
    private :

        std::stack<int> _stack;
        int _arg1;
        int _arg2;

    public :

        RPN(void);
        ~RPN(void);
        RPN(const RPN & src);
        RPN & operator=(const RPN & rhs);

        void    fillStack(char *argv);

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
