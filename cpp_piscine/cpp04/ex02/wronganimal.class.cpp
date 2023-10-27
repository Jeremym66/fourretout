/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:19:25 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/18 08:12:02 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wronganimal.class.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
    std::cout << "constructor WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "constructor WrongAnimal" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "destructor WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & a)
{
    std::cout << "constructor copy WrongAnimal" << std::endl;
    *this = a;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs)
{
    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}

std::string WrongAnimal::getType(void) const
{
    return (this->_type);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "I'm ANIMAAAAAAAAAAAAAAAAL" << std::endl;
}
