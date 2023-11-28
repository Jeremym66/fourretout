/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:09:54 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/28 09:10:09 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "ASpell.hpp"

class Fireball : public ASpell
{
    public :

        Fireball(void);
        ~Fireball(void);

        ASpell * clone() const;
};