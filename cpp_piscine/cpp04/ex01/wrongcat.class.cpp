/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:38:26 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/18 08:11:47 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrongcat.class.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
    this->_type = "WrongCat";
    std::cout << "constructor WrongCat" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << "destructor WrongCat" << std::endl;
}

WrongCat::WrongCat(WrongCat const & a)
{
    std::cout << "constructor copy WrongCat" << std::endl;
    *this = a;
}

WrongCat & WrongCat::operator=(WrongCat const & rhs)
{
    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}

void    WrongCat::makeSound(void) const
{
    std::cout << "MIAaaaouuuOOOUUUUU " << std::endl;
}
