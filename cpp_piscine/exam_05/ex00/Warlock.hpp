/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 06:26:16 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/24 06:49:39 by jmetezea         ###   ########.fr       */
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
        Warlock(const std::string namee, const std::string titlee);

        const std::string getName(void) const;
        const std::string getTitle(void) const;
        void setTitle(const std::string str);

        void introduce(void) const;

};