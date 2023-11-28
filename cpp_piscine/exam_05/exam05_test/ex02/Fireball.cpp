/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:08:44 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/28 09:10:56 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fireball.hpp"

Fireball::Fireball(void) : ASpell::ASpell("Fireball", "burnt to a crisp")
{
    // std::cout << "constructor Fireball" << name << effects << std::endl;
}

Fireball::~Fireball(void)
{
    // std::cout << "destructor Fireball" << std::endl;
}

ASpell * Fireball::clone() const
{
    ASpell * temp = new Fireball();
    return temp; 
}
