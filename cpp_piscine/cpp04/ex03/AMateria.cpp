/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 07:57:00 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/15 11:12:21 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{
    std::cout << "constructor AMateria : " << this->_type << std::endl;
}

AMateria::~AMateria(void)
{
    std::cout << "destructor AMateria" << std::endl;
}

std::string const & AMateria::getType() const //Returns the materia type
{
    return (this->_type);
}