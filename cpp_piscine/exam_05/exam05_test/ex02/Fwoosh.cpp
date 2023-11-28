/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:11:22 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/28 09:02:49 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh(void) : ASpell::ASpell("Fwoosh", "Fwooshed")
{
    // std::cout << "constructor Fwoosh" << name << effects << std::endl;
}

Fwoosh::~Fwoosh(void)
{
    // std::cout << "destructor Fwoosh" << std::endl;
}

ASpell * Fwoosh::clone() const
{
    ASpell * temp = new Fwoosh();
    return temp; 
}
