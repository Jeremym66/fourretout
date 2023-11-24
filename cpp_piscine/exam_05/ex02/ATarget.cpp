/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:41:58 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/23 18:48:30 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget(void) {}

ATarget::~ATarget(void) {}

ATarget::ATarget(const std::string & typee) : type(typee) {}

ATarget::ATarget(const ATarget & src) { *this = src; }

ATarget & ATarget::operator=(const ATarget & rhs)
{
    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return(*this);
}

const std::string & ATarget::getType() const
{
    return (this->type);
}

void ATarget::getHitBySpell(ASpell const & spell) const
{
    std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}
