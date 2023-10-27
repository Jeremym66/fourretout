/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:19:25 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/24 13:35:48 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.class.hpp"

AAnimal::AAnimal(void) : _type("AAnimal")
{
    std::cout << "constructor AAnimal" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
    std::cout << "constructor AAnimal" << std::endl;
}

AAnimal::~AAnimal(void)
{
    std::cout << "destructor AAnimal" << std::endl;
}

AAnimal::AAnimal(AAnimal const & a)
{
    std::cout << "constructor copy AAnimal" << std::endl;
    *this = a;
}

AAnimal & AAnimal::operator=(AAnimal const & rhs)
{
    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}

std::string AAnimal::getType(void) const
{
    return (this->_type);
}

void    AAnimal::makeSound(void) const
{
    std::cout << "I'm ANIMAAAAAAAAAAAAAAAAL" << std::endl;
}
