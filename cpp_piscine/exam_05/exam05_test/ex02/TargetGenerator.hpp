/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:12:07 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/28 11:23:57 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <map>

#include "ATarget.hpp"

class TargetGenerator
{
    private :

        TargetGenerator(const TargetGenerator & src);
        TargetGenerator & operator=(const TargetGenerator & rhs);

        std::map<std::string, ATarget *> book;

    public :

        TargetGenerator(void);
        ~TargetGenerator(void);

        void    learnTargetType(ATarget * spell);
        void    forgetTargetType(std::string const & name);
        ATarget * createTarget(std::string const & name);

};