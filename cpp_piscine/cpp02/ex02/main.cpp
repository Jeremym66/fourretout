/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:07:55 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/13 11:55:55 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

int	main(void)
{
    Fixed a;
    Fixed const b( Fixed(5.05f) * Fixed(2) );
    // Fixed const c( 2 );
    // Fixed const d( 5 );
    // Fixed const e( 0 );

    // a = Fixed( 1234.4321f );
    
    // std::cout << "a is " << a << std::endl;
    // std::cout << "b is " << b << std::endl;
    // std::cout << "c is " << c << std::endl;
    // std::cout << "d is " << d << std::endl;

    // a = b + c;

    // std::cout << "a is " << a << std::endl;

    // a = b + d;

    // std::cout << "a is " << a << std::endl;

    // a = b - c;

    // std::cout << "a is " << a << std::endl;
    
    // a = b * c;

    // std::cout << "a is " << a << std::endl;

    // a = b / e;

    // std::cout << "a is " << a << std::endl;

    // if (b < c)
    //     std::cout << "B plus petit ca marcheeeeeee" << std::endl;
    // else
    //     std::cout << "B nest pas plus petit ca marcheeeeeee" << std::endl;

    // std::cout << Fixed::max( c, b ) << std::endl;

    // a = 0;
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;
    
    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}