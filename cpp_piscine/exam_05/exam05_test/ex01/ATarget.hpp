/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 07:41:57 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/28 08:34:50 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "ASpell.hpp"

class ASpell;

class ATarget
{
    protected :

        std::string type;

    public :

        ATarget(void);
        ATarget(const ATarget & src);
        ATarget & operator=(const ATarget & rhs);
        virtual ~ATarget(void);
        
        ATarget(std::string const & typee);

        std::string const getType(void) const;

        void getHitBySpell(const ASpell & spell) const;
        
        virtual ATarget * clone() const = 0;

};