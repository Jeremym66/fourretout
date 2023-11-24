/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:16:27 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/23 18:47:39 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell(void) {}

ASpell::~ASpell(void) {}

ASpell::ASpell(const std::string & namee, const std::string & effects) : name(namee), effects(effects)
{}

ASpell::ASpell(const ASpell & src) { *this = src; }

ASpell & ASpell::operator=(const ASpell & rhs)
{
    if (this != &rhs)
    {
        this->name = rhs.name;
        this->effects = rhs.effects;
    }
    return(*this);
}

const std::string & ASpell::getName() const
{
    return (this->name);
}

const std::string & ASpell::getEffects() const
{
    return (this->effects);
}

void ASpell::launch(const ATarget & target) const
{
    target.getHitBySpell(*this);
}