/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.class.hpp                                   :+:      :+:    :+:   */
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

class WrongAnimal
{
    public :

        WrongAnimal(void);
        WrongAnimal(std::string type);
        ~WrongAnimal(void);
        WrongAnimal(WrongAnimal const & a);
        WrongAnimal & operator=(WrongAnimal const & rhs);

        std::string getType(void) const;
        void    makeSound(void) const;

    protected :

        std::string _type;
};
