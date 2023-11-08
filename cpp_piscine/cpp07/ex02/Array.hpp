/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:13:37 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/07 08:17:14 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>

template <typename T>
class Array 
{
	private:
		T	*data;
		int	_size;
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& copy);
		~Array(void);

		T&		operator[](int idx) const;
		Array&	operator=(const Array& other);
		int		getsize(void) const;

        class Exception : public std::exception
        {
            private :

                const char  *_msg;
            
            public :

                Exception(void);
                Exception(const char *_msg);
                const char* what() const throw()
                {
                    return this->_msg;
                }
        };
};

template <typename T>
std::ostream&	operator<<(std::ostream& out, const Array<T>& array);

