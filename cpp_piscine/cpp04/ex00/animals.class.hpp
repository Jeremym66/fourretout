/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animals.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <kaly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:00:26 by kaly              #+#    #+#             */
/*   Updated: 2023/10/17 18:09:46 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Animal
{
    public :

        Animals(void);
        ~Animals(void);
        Animals(Animal const & a);
        Animal & operator=(Animal const & rhs);

    protected :

        std::string name;
}