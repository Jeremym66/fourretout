/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:19:16 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/18 08:11:53 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Animal
{
    public :

        Animal(void);
        Animal(std::string type);
        ~Animal(void);
        Animal(Animal const & a);
        Animal & operator=(Animal const & rhs);

        std::string getType(void) const;
        virtual void    makeSound(void) const;

    protected :

        std::string _type;
};
