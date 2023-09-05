/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 07:28:20 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/05 07:28:24 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.class.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
    std::cout << "constructor Weapon : " << type << std::endl;
}

Weapon::~Weapon()
{
    std::cout << "destructor Weapon" << std::endl;
}

const std::string&    Weapon::getType()
{
    return this->type;
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}