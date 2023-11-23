/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:11:46 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/23 18:50:58 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
    private :

        Warlock(void);
        Warlock(const Warlock & src);
        Warlock & operator=(const Warlock & rhs);
        
        std::string name;
        std::string title;
        std::map<std::string, ASpell *> book;

    public :

        Warlock(const std::string & namee, const std::string & titlee);
        ~Warlock(void);

        const std::string & getName() const;
        const std::string & getTitle() const;
        void setTitle(const std::string & str);

        void introduce() const;

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string name);
        void launchSpell(std::string name, ATarget const & target);

};