//
// Created by aymeric on 16/08/23.
//

#include "Fixed.hpp"


Fixed::Fixed() : _vnvf(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed & Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_vnvf = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_vnvf);
}

void Fixed::setRawBits( int const raw ){
	this->_vnvf = raw;
}