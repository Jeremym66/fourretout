/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:18:42 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/28 11:21:42 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <map>

#include "ASpell.hpp"

class SpellBook
{
    private :

        SpellBook(const SpellBook & src);
        SpellBook & operator=(const SpellBook & rhs);

        std::map<std::string, ASpell *> book;

    public :

        SpellBook(void);
        ~SpellBook(void);

        void    learnSpell(ASpell * spell);
        void    forgetSpell(std::string const & name);
        ASpell * createSpell(std::string const & name);

};