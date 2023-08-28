//
// Created by aymeric on 16/08/23.
//

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed(void);
	~Fixed();
	Fixed( const int n );
	Fixed( const float n );
	Fixed(Fixed const & src);
	Fixed & operator=(Fixed const & rhs);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float   toFloat( void ) const;
	int     toInt( void ) const;
	bool    operator>( const Fixed &rhs ) const ;
	bool    operator<( const Fixed &rhs ) const ;
	bool    operator>=( const Fixed &rhs ) const ;
	bool    operator<=( const Fixed &rhs ) const ;
	bool    operator==( const Fixed &rhs ) const ;
	bool    operator!=( const Fixed &rhs ) const ;

	Fixed   operator+( const Fixed &rhs ) const ;
	Fixed   operator-( const Fixed &rhs ) const ;
	Fixed   operator*( const Fixed &rhs ) const ;
	Fixed   operator/( const Fixed &rhs ) const ;

	Fixed&  operator++( void );
	Fixed   operator++( int );
	Fixed&  operator--( void );
	Fixed   operator--( int );

	static Fixed& min( Fixed &a, Fixed &b );
	static const Fixed& min( const Fixed &a, const Fixed &b );
	static Fixed& max( Fixed &a, Fixed &b );
	static const Fixed& max( const Fixed &a, const Fixed &b );
private:
	int _vnvf;
	static const int _bpf = 8;
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif //FIXED_HPP
