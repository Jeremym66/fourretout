/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:10:14 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/28 09:10:22 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "ASpell.hpp"

class Polymorph : public ASpell
{
    public :

        Polymorph(void);
        ~Polymorph(void);

        ASpell * clone() const;
};