/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:20:00 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/23 18:21:27 by jmetezea         ###   ########.fr       */
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

        Dummy * clone(void) const;
};