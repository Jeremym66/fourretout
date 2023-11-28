/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:22:28 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/28 08:34:59 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "ATarget.hpp"

class Dummy : public ATarget
{
    public :

        Dummy(void);
        ~Dummy(void);

        ATarget * clone() const;
};