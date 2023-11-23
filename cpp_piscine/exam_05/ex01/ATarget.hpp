/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:40:49 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/23 18:46:12 by jmetezea         ###   ########.fr       */
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
        ATarget(const std::string & typee);
        ~ATarget(void);

        const std::string & getType() const;
        void getHitBySpell(const ASpell & spell) const;

        virtual ATarget * clone(void) const = 0;
};