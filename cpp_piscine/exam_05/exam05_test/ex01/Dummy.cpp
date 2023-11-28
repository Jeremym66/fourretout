/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:23:09 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/28 09:03:12 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy(void) : ATarget::ATarget("Target Practice Dummy")
{
    // std::cout << "constructor Dummy" << type << std::endl;
}

Dummy::~Dummy(void)
{
    // std::cout << "destructor Dummy" << std::endl;
}

ATarget * Dummy::clone() const
{
    ATarget * temp = new Dummy();
    return temp; 
}