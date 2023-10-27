/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:08:25 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/24 13:35:54 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.class.hpp"

Dog::Dog(void) : AAnimal("Dog")
{
    this->_type = "Dog";
    this->_Mybrain = new Brain();
    int randomIndex = std::rand() % 100;
    this->MyIdea = this->_Mybrain->ideas[randomIndex];
    std::cout << "constructor Dog" << std::endl;
}

Dog::~Dog(void)
{
    delete this->_Mybrain;
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
    std::cout << MyIdea << std::endl;
}
