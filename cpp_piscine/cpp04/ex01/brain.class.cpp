/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:33:51 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/18 15:47:47 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.class.hpp"

Brain::Brain(void)
{
    this->generateIdeas();
    std::cout << "constructor brain" << std::endl;
}

Brain::~Brain(void)
{
    std::cout << "destructor brain" << std::endl;
}

Brain::Brain(Brain const & a)
{
    std::cout << "constructor copy brain" << std::endl;
    *this = a;
}

Brain & Brain::operator=(Brain const & rhs)
{
    int i = -1;
    if (this != &rhs)
    {
        while (++i < 100)
            ideas[i] = rhs.ideas[i];
    }
    return (*this);
}

std::string Brain::getIdeas(void) const
{
    return this->ideas[0];
}

void    Brain::generateIdeas(void)
{
    int i = -1;

    while (++i < 100)
        this->ideas[i] = "Idea number " + (i + 1);
    return;
}
