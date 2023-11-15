/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:38:05 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/15 10:28:53 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
    std::cout << "constructor Ice : " << this->_type << std::endl;
}

Ice::~Ice(void)
{
    std::cout << "destructor Ice" << std::endl;
}

std::string const & Ice::getType() const //Returns the materia type
{
    return (this->_type);
}