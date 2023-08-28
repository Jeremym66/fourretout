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

//----------------- Comparison operators -----------------//

bool    Fixed::operator>( const Fixed &rhs ) const {
	return this->getRawBits() > rhs.getRawBits();
}

bool    Fixed::operator<( const Fixed &rhs ) const {
	return this->getRawBits() < rhs.getRawBits();
}

bool    Fixed::operator>=( const Fixed &rhs ) const {
	return this->getRawBits() >= rhs.getRawBits();
}

bool   Fixed::operator<=( const Fixed &rhs ) const {
	return this->getRawBits() <= rhs.getRawBits();
}

bool  Fixed::operator==( const Fixed &rhs ) const {
	return this->getRawBits() == rhs.getRawBits();
}

bool    Fixed::operator!=( const Fixed &rhs ) const {
	return this->getRawBits() != rhs.getRawBits();
}

//------------------ Arithmetic operators ------------------//

Fixed   Fixed::operator+( const Fixed &rhs ) const {
	return Fixed( this->toFloat() + rhs.toFloat() );
}

Fixed   Fixed::operator-( const Fixed &rhs ) const {
	return Fixed( this->toFloat() - rhs.toFloat() );
}

Fixed   Fixed::operator*( const Fixed &rhs ) const {
	return Fixed( this->toFloat() * rhs.toFloat() );
}

Fixed   Fixed::operator/( const Fixed &rhs ) const {
	return Fixed( this->toFloat() / rhs.toFloat() );
}

//------------------ Increment/Decrement operators ------------------//

Fixed&   Fixed::operator++( void ) {
	++this->_vnvf;
	return *this;
}

Fixed   Fixed::operator++( int ) {
	Fixed tmp( *this );
	tmp._vnvf = this->_vnvf++;
	return tmp;
}

Fixed& Fixed::operator--( void ) {
	--this->_vnvf;
	return *this;
}

Fixed Fixed::operator--( int ) {
	Fixed tmp( *this );
	tmp._vnvf = this->_vnvf--;
	return tmp;
}

//----------------------- Max and Min ----------------------//

Fixed& Fixed::min( Fixed &a, Fixed &b ) {
	if ( a.getRawBits() < b.getRawBits() )
		return a;
	return b;
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b ) {
	if ( a.getRawBits() < b.getRawBits() )
		return a;
	return b;
}

Fixed& Fixed::max( Fixed &a, Fixed &b ) {
	if ( a.getRawBits() > b.getRawBits() )
		return a;
	return b;
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b ) {
	if ( a.getRawBits() > b.getRawBits() )
		return a;
	return b;
}