/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:20:03 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/23 18:23:29 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy(void) : ATarget::ATarget("Target Practice Dummy")
{}

Dummy::~Dummy(void) {}

Dummy * Dummy::clone(void) const
{
    Dummy * dum = new Dummy();
    return (dum);
}