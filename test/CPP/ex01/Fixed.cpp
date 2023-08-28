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

Fixed::Fixed( const int n ) : _vnvf( n << _bpf ) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float n ) : _vnvf( std::roundf( n * ( 1 << _bpf ) ) ) {
	std::cout << "Float constructor called" << std::endl;
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
	return (this->_vnvf);
}

void Fixed::setRawBits( int const raw ){
	this->_vnvf = raw;
}

float   Fixed::toFloat( void ) const {
	return static_cast<float>( this->getRawBits() ) / ( 1 << _bpf );
}

int     Fixed::toInt( void ) const {
	return this->_vnvf >> _bpf;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
	o << i.toFloat();
	return o;
}