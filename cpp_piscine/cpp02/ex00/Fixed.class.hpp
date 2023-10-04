/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:07:55 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/04 02:53:06 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Fixed {

public :

        Fixed(void);
        ~Fixed(void);
        Fixed(Fixed const & src);
        Fixed & operator=(Fixed const & rhs);

        void setRawBits(int const raw);
        int getRawBits(void) const;
        

private :

        int _val;
        static const int _bit = 8;
};
