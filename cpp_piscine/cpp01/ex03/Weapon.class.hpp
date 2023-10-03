/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 07:28:02 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/03 08:59:23 by jmetezea         ###   ########.fr       */
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

    Weapon(std::string type);
    ~Weapon();

    const std::string   &getType() const;
    void	setType(std::string type);

};

#endif