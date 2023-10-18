/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:38:26 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/18 08:11:47 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.class.hpp"

Cat::Cat(void) : Animal("Cat")
{
    this->_type = "Cat";
    std::cout << "constructor Cat" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << "destructor Cat" << std::endl;
}

Cat::Cat(Cat const & a)
{
    std::cout << "constructor copy Cat" << std::endl;
    *this = a;
}

Cat & Cat::operator=(Cat const & rhs)
{
    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << "MIAaaaouuuOOOUUUUU " << std::endl;
}
