/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:12:44 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/28 09:13:00 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "ATarget.hpp"

class BrickWall : public ATarget
{
    public :

        BrickWall(void);
        ~BrickWall(void);

        ATarget * clone() const;
};