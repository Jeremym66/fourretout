/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:45:25 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/28 07:10:56 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Warlock
{
    private :

        Warlock(void);
        Warlock(const Warlock & src);
        Warlock & operator=(const Warlock & rhs);

        std::string name;
        std::string title;

    public :

        ~Warlock(void);
        
        Warlock(std::string const namee, std::string const titlee);

        std::string const getName(void) const;
        std::string const getTitle(void) const;

        void setTitle(std::string const str);
        
        void introduce(void) const;

};