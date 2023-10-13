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
    // std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::~Fixed(void)
{
    // std::cout << "Destructor called" << std::endl;
    return;
}

Fixed::Fixed(Fixed const & src)
{
    // std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::Fixed(int const i) : _val( i << _bit )
{
    // std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed(float const fl) : _val( std::roundf( fl * ( 1 << _bit ) ) )
{
	// std::cout << "Float constructor called" << std::endl;
	return;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_val = rhs.getRawBits();
    return(*this);
}

bool    Fixed::operator<(Fixed const & rhs) const
{
    return this->_val < rhs.getRawBits();
}

bool    Fixed::operator>(Fixed const & rhs) const
{
    return this->_val > rhs.getRawBits();
}

bool    Fixed::operator>=(Fixed const & rhs) const
{
    return this->_val >= rhs.getRawBits();
}

bool    Fixed::operator<=(Fixed const & rhs) const
{
    return this->_val <= rhs.getRawBits();
}

bool    Fixed::operator==(Fixed const & rhs) const
{
    return this->_val == rhs.getRawBits();
}

bool    Fixed::operator!=(Fixed const & rhs) const
{
    return this->_val != rhs.getRawBits();
}

Fixed   Fixed::operator+(Fixed const & rhs) const
{
    // std::cout << "Addition assignment operator called with " << this->toFloat();
    // std::cout << " and " << rhs.toFloat() << std::endl;
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed   Fixed::operator-(Fixed const & rhs) const
{
    // std::cout << "Soustraction assignment operator called with " << this->toFloat();
    // std::cout << " and " << rhs.toFloat() << std::endl;
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed   Fixed::operator*(Fixed const & rhs) const
{
    // std::cout << "Multiplication assignment operator called with " << this->toFloat();
    // std::cout << " and " << rhs.toFloat() << std::endl;
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed   Fixed::operator/(Fixed const & rhs) const
{
    // std::cout << "division assignment operator called with " << this->toFloat();
    // std::cout << " and " << rhs.toFloat() << std::endl;
    if (rhs.getRawBits() == 0)
        return (Fixed(0));
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed & Fixed::operator++(void)
{
    this->_val++;
    return (*this);
}

Fixed & Fixed::operator--(void)
{
    this->_val--;
    return (*this);
}

Fixed   Fixed::operator++(int n)
{
    Fixed temp(*this);

    if (!n)
		n = 1;
    this->_val++;
    return (temp);
}

Fixed   Fixed::operator--(int n)
{
    Fixed temp(*this);

    if (!n)
		n = 1;
    this->_val--;
    return (temp);
}

void Fixed::setRawBits(int const raw)
{   
    // std::cout << "setRawBits member function called" << std::endl;
    this->_val = raw;
}

int Fixed::getRawBits(void) const
{
    return (this->_val);
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

Fixed const & Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a > b)
		return (b);
	return (a);
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	if (a > b)
		return (b);
	return (a);
}