/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:38:29 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/18 08:11:43 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "wronganimal.class.hpp"

class WrongCat : public WrongAnimal
{
    public :

        WrongCat(void);
        ~WrongCat(void);
        WrongCat(WrongCat const & a);
        WrongCat & operator=(WrongCat const & rhs);

        void    makeSound(void) const;

};