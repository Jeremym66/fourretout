/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 07:28:02 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/05 07:28:05 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_CLASS_HPP__
# define __WEAPON_CLASS_HPP__

#include <iostream>

class Weapon
{

private:

    std::string _type;

public:

    Weapon(/* args */);
    ~Weapon();

    const std::string&    getType();
    void	Weapon::setType(std::string type)

};

#endif