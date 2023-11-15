/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:22:24 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/15 11:31:55 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class AMateria
{
    protected:

        std::string   _type;

    public:
            
        AMateria(std::string const & type);
        virtual ~AMateria();

        std::string const & getType() const; //Returns the materia type
        
        // virtual AMateria* clone() const = 0;
        // virtual void use(ICharacter& target);
};