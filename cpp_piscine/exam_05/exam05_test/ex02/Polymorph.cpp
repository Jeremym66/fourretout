/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:08:48 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/28 09:11:11 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Polymorph.hpp"

Polymorph::Polymorph(void) : ASpell::ASpell("Polymorph", "turned into a critter")
{
    // std::cout << "constructor Polymorph" << name << effects << std::endl;
}

Polymorph::~Polymorph(void)
{
    // std::cout << "destructor Polymorph" << std::endl;
}

ASpell * Polymorph::clone() const
{
    ASpell * temp = new Polymorph();
    return temp; 
}
