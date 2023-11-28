/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:11:55 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/28 08:33:10 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
    public :

        Fwoosh(void);
        ~Fwoosh(void);

        ASpell * clone() const;
};