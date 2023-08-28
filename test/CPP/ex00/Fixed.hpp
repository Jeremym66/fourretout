//
// Created by aymeric on 16/08/23.
//

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>


class Fixed {
public:
	Fixed(void);
	~Fixed();
	Fixed(Fixed const & src);
	Fixed & operator=(Fixed const & rhs);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
private:
	int _vnvf;
	static const int _bpf = 8;
};


#endif //FIXED_HPP
