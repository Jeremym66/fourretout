/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:45:33 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/28 07:53:00 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

// Warlock::Warlock(void)
// {
//     std::cout << "constructor Warlock" << std::endl;
// }

Warlock::~Warlock(void)
{
    std::cout << name << ": My job here is done!" << std::endl;
}

// Warlock::Warlock(const Warlock & src) {*this = src;}

// Warlock & Warlock::operator=(const Warlock & rhs) 
// {
//     if (this != &rhs)
//     {
//         name = rhs.name;
//         title = rhs.title;   
//     }
//     return (*this);
// }

Warlock::Warlock(std::string const & namee, std::string const & titlee) : name(namee), title(titlee)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

std::string const Warlock::getName(void) const
{
    return(this->name);
}

std::string const Warlock::getTitle(void) const
{
    return(this->title);
}

void Warlock::setTitle(std::string const str)
{
    title = str;
}

void Warlock::introduce(void) const
{
    std::cout << name << ": I am " << name << ", ";
    std::cout << title << "!" << std::endl;
}

