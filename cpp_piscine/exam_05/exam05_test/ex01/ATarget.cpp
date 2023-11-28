/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 07:41:52 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/28 09:03:01 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget(void)
{
    // std::cout << "constructor ATarget" << std::endl;
}

ATarget::~ATarget(void)
{
    // std::cout << "destructor ATarget" << std::endl;
}

ATarget::ATarget(const ATarget & src) {*this = src;}

ATarget & ATarget::operator=(const ATarget & rhs) 
{
    if (this != &rhs)
    {
        type = rhs.type;   
    }
    return (*this);
}

ATarget::ATarget(std::string const & typee) : type(typee)
{
    // std::cout << "hummmm Atarget : " << type << std::endl;
}

std::string const ATarget::getType(void) const
{
    return(this->type);
}

void ATarget::getHitBySpell(const ASpell & spell) const
{
    std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}
