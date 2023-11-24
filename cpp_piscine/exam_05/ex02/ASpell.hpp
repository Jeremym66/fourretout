/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:13:05 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/23 18:46:24 by jmetezea         ###   ########.fr       */
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

        ASpell(const std::string & name, const std::string & effects);

        const std::string & getName() const;
        const std::string & getEffects() const;

        void launch(const ATarget & target) const;
        
        virtual ASpell * clone(void) const = 0;
};
