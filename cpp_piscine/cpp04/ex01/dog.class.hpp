/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:09:03 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/24 12:13:04 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "animal.class.hpp"
#include "brain.class.hpp"

class Dog : public Animal
{
    public :

        Dog(void);
        ~Dog(void);
        Dog(Dog const & a);
        Dog & operator=(Dog const & rhs);

        void    makeSound(void) const;

        std::string MyIdea;

    private :

        Brain   *_Mybrain;

};