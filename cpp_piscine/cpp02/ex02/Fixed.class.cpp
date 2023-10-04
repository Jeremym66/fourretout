/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:07:55 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/04 01:06:38 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed(void) : _val(0)
{
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::Fixed(int const i) : _val( i << _bit )
{
    std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed(float const fl) : _val( std::roundf( fl * ( 1 << _bit ) ) )
{
	std::cout << "Float constructor called" << std::endl;
	return;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_val = rhs.getRawBits();
    return(*this);
}

int Fixed::getRawBits(void) const
{
    return (this->_val);
}

void Fixed::setRawBits(int const raw)
{   
    std::cout << "setRawBits member function called" << std::endl;
    this->_val = raw;
}

float   Fixed::toFloat( void ) const 
{
	return static_cast<float>( this->getRawBits() ) / ( 1 << _bit );
}

int     Fixed::toInt( void ) const 
{
	return this->_val >> _bit;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return o;
}