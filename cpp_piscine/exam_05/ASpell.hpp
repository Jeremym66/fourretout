/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:13:05 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/22 19:50:08 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <string>

class ASpell
{
    protected :

        std::string name;
        std::string effects;

    public :

        ASpell(void);
        ASpell(const ASpell & src);
        ASpell & operator=(const ASpell & rhs);
        ASpell(const std::string & name, const std::string & title);
        ~ASpell(void);

        const std::string & getName() const;
        const std::string & getEffects() const;

        // virtual ASpell * clone(void) const = 0;
};
