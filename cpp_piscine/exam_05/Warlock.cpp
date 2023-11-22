/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:11:38 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/22 19:16:58 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(const std::string & namee, const std::string & titlee) : name(namee), title(titlee)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void)
{
    std::cout << name << ": My job here is done!" << std::endl;
}

const std::string & Warlock::getName() const
{
    return (this->name);
}

const std::string & Warlock::getTitle() const
{
    return (this->title);
}

void Warlock::setTitle(const std::string & str)
{
    title = str;
}

void Warlock::introduce() const
{
    std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}