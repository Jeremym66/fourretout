/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:45:33 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/28 10:39:49 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::~Warlock(void)
{
    std::cout << name << ": My job here is done!" << std::endl;
}

Warlock::Warlock(std::string const & namee, std::string const & titlee) : name(namee), title(titlee)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

std::string const Warlock::getName(void) const
{
    return(this->name);
}

std::string const Warlock::getTitle(void) const
{
    return(this->title);
}

void Warlock::setTitle(std::string const str)
{
    title = str;
}

void Warlock::introduce(void) const
{
    std::cout << name << ": I am " << name << ", ";
    std::cout << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell * spell)
{
    book.learnSpell(spell);
}

void Warlock::forgetSpell(std::string name)
{
    book.forgetSpell(name);
}

void    Warlock::launchSpell(std::string name, ATarget const & target)
{
    ATarget const * test = 0;
    if (test == &target)
        return;
    ASpell * spell = book.createSpell(name);
    if (spell)
        spell->launch(target);
}
