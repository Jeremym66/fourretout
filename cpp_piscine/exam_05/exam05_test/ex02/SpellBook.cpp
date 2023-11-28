/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:18:36 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/28 10:41:13 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook(void)
{}

SpellBook::~SpellBook(void)
{
    std::map<std::string, ASpell *>::iterator it = book.begin();
    while (it != book.end())
    {
        delete it->second;
        it++;
    }
    book.clear();
}

void SpellBook::learnSpell(ASpell * spell)
{
    if (spell)
        book.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void SpellBook::forgetSpell(std::string const & name)
{
    std::map<std::string, ASpell *>::iterator it = book.find(name);
    if (it != book.end())
        delete it->second;
    book.erase(name);
}

ASpell * SpellBook::createSpell(std::string const & name)
{
    std::map<std::string, ASpell *>::iterator it = book.find(name);
    if (it != book.end())
        return book[name];
    return NULL;
}