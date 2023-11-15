/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:32:41 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/15 11:10:54 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "AMateria.hpp"

class Ice : public AMateria
{   
    public :

        Ice(void);
        ~Ice();

        std::string const & getType() const; //Returns the materia type
        
        // virtual Ice* clone() const = 0;
        // virtual void use(ICharacter& target);
};