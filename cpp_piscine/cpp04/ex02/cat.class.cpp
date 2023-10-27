/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:38:26 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/24 13:35:51 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.class.hpp"

Cat::Cat(void) : AAnimal("Cat")
{
    this->_type = "Cat";
    this->_Mybrain = new Brain();
    int randomIndex = std::rand() % 100;
    this->MyIdea = this->_Mybrain->ideas[randomIndex];
    std::cout << "constructor Cat" << std::endl;
}

Cat::~Cat(void)
{
    delete this->_Mybrain;
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
        this->_Mybrain = new Brain();
    }
    return (*this);
}
void    Cat::makeSound(void) const
{
    std::cout << "MIAaaaouuuOOOUUUUU " << std::endl;
    std::cout << MyIdea << std::endl;
}
