/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 07:30:19 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/28 08:33:33 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "ATarget.hpp"

class ATarget;

class ASpell
{
    protected :

        std::string name;
        std::string effects;

    public :

        ASpell(void);
        ASpell(const ASpell & src);
        ASpell & operator=(const ASpell & rhs);
        virtual ~ASpell(void);
        
        ASpell(std::string const & namee, std::string const & effectse);

        std::string const getName(void) const;
        std::string const getEffects(void) const;

        void    launch(const ATarget & tar) const;

        virtual ASpell * clone() const = 0;

};