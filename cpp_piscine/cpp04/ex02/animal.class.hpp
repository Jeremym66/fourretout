/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:19:16 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/24 13:32:53 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class AAnimal
{
    public :

        AAnimal(void);
        AAnimal(std::string type);
        virtual ~AAnimal(void);
        AAnimal(AAnimal const & a);
        AAnimal & operator=(AAnimal const & rhs);

        std::string getType(void) const;
        virtual void    makeSound(void) const = 0;

    protected :

        std::string _type;
};
