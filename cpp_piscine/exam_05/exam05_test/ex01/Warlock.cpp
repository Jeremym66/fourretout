/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:45:33 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/28 09:36:10 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::~Warlock(void)
{
    std::map<std::string, ASpell *>::iterator it = book.begin();
    while (it != book.end())
    {
        delete it->second;
        it++;
    }
    book.clear();
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
    if (spell)
        book.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void Warlock::forgetSpell(std::string name)
{
    std::map<std::string, ASpell *>::iterator it = book.find(name);
    if (it != book.end())
        delete it->second;
    book.erase(name);
}

void    Warlock::launchSpell(std::string name, ATarget const & target)
{
    ASpell * spell = book[name];
    if (spell)
        spell->launch(target);
}
