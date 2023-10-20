/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:19:16 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/20 15:11:41 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "brain.class.hpp"

class Animal
{
    public :

        Animal(void);
        Animal(std::string type);
        virtual ~Animal(void);
        Animal(Animal const & a);
        Animal & operator=(Animal const & rhs);

        std::string getType(void) const;
        virtual void    makeSound(void) const;
        virtual Brain *getBrain(void) const;

    protected :

        std::string _type;
};
