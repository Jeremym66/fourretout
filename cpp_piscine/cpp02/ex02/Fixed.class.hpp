/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:07:55 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/04 03:47:49 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath> 

class Fixed {
public :

        Fixed(void);
        Fixed(Fixed const & src);
        Fixed(int const i);
        Fixed(float const i);

        ~Fixed();

        Fixed & operator=(Fixed const & rhs);

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;

private :

        int   _val;
        static const int _bit = 8;
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );
