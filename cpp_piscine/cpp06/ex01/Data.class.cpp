/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <kaly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:59:19 by kaly              #+#    #+#             */
/*   Updated: 2023/11/02 18:15:34 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.class.hpp"

Data::Data() : _nbr(42)
{
	std::cout << "Data constructor" << std::endl;
}

Data::Data(Data const &src)
{
	std::cout << "Data copy constructor" << std::endl;
	*this = src;
}

Data::~Data()
{
	std::cout << "Data destructor" << std::endl;
}

Data &	Data::operator=(Data const &rSym) 
{
	if (this != &rSym) 
		this->_nbr = rSym._nbr;
	return *this;
}

int	Data::getnbr() const
{
	return this->_nbr;
}

std::ostream &	operator<<(std::ostream & o, Data const &rSym)
{
	o << rSym.getnbr();
	return o;
}

