/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:38:29 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/24 10:46:23 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "animal.class.hpp"

class Cat : public Animal
{
    public :

        Cat(void);
        ~Cat(void);
        Cat(Cat const & a);
        Cat & operator=(Cat const & rhs);

        void    makeSound(void) const;

};