/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:08:25 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/18 08:11:36 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.class.hpp"

Dog::Dog(void) : Animal("Dog")
{
    this->_type = "Dog";
    std::cout << "constructor Dog" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "destructor Dog" << std::endl;
}

Dog::Dog(Dog const & a)
{
    std::cout << "constructor copy Dog" << std::endl;
    *this = a;
}

Dog & Dog::operator=(Dog const & rhs)
{
    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "Waff Waff WAFFFFFFFFF ouhaf" << std::endl;
}
