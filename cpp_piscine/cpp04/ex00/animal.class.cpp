/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:19:25 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/18 08:14:44 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.class.hpp"

Animal::Animal(void) : _type("Animal")
{
    std::cout << "constructor animal" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "constructor animal" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "destructor animal" << std::endl;
}

Animal::Animal(Animal const & a)
{
    std::cout << "constructor copy animal" << std::endl;
    *this = a;
}

Animal & Animal::operator=(Animal const & rhs)
{
    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}

std::string Animal::getType(void) const
{
    return (this->_type);
}

void    Animal::makeSound(void) const
{
    std::cout << "I'm ANIMAAAAAAAAAAAAAAAAL" << std::endl;
}
