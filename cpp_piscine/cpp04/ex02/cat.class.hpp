/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:38:29 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/24 13:35:56 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "animal.class.hpp"
#include "brain.class.hpp"

class Cat : public AAnimal
{
    public :

        Cat(void);
        ~Cat(void);
        Cat(Cat const & a);
        Cat & operator=(Cat const & rhs);

        void    makeSound(void) const;

        std::string MyIdea;
        
    private :

        Brain   *_Mybrain;

};