/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:37:32 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/23 16:43:15 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh(void) : ASpell::ASpell("Fwoosh", "fwooshed")
{}

Fwoosh::~Fwoosh(void) {}

Fwoosh * Fwoosh::clone(void) const
{
    Fwoosh * fw = new Fwoosh();
    return (fw);
}