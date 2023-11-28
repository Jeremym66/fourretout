/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 07:30:23 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/28 09:02:39 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell(void)
{
    // std::cout << "constructor ASpell" << std::endl;
}

ASpell::~ASpell(void)
{
    // std::cout << "destructor ASpell" << std::endl;
}

ASpell::ASpell(const ASpell & src) {*this = src;}

ASpell & ASpell::operator=(const ASpell & rhs) 
{
    if (this != &rhs)
    {
        name = rhs.name;
        effects = rhs.effects;   
    }
    return (*this);
}

ASpell::ASpell(std::string const & namee, std::string const & effectse) : name(namee), effects(effectse)
{}

std::string const ASpell::getName(void) const
{
    return(this->name);
}

std::string const ASpell::getEffects(void) const
{
    return(this->effects);
}

void    ASpell::launch(const ATarget & tar) const
{
    tar.getHitBySpell(*this);
}