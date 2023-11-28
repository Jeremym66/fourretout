/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:13:24 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/28 09:14:55 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall::BrickWall(void) : ATarget::ATarget("Inconspicuous Red-brick Wall")
{
    // std::cout << "constructor BrickWall" << type << std::endl;
}

BrickWall::~BrickWall(void)
{
    // std::cout << "destructor BrickWall" << std::endl;
}

ATarget * BrickWall::clone() const
{
    ATarget * temp = new BrickWall();
    return temp; 
}