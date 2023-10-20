/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:38:26 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/20 15:18:27 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.class.hpp"
// #include "brain.class.hpp"

Cat::Cat(void) : Animal("Cat")
{
    this->_type = "Cat";
    this->_Brain = new Brain();
    std::cout << "constructor Cat" << std::endl;
}

Cat::~Cat(void)
{
    delete this->_Brain;
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
    {
        this->_type = rhs.getType();
        this->_Brain = new Brain();
    }
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << "MIAaaaouuuOOOUUUUU " << std::endl;
}

Brain *Cat::getBrain(void) const
{
    // std::cout << this->_Brain->getIdeas << std::endl;
    return (this->_Brain);
}
