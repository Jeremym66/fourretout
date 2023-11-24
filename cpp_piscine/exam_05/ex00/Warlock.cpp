/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 06:25:59 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/24 06:48:40 by jmetezea         ###   ########.fr       */
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

// Warlock::Warlock(const Warlock & src)
// {
//     std::cout << "constructor Warlock copy" << std::endl;
//     *this = src;
// }

// Warlock & Warlock::operator=(const Warlock & rhs)
// {
//     if (this != &rhs)
//     {
//         name = rhs.name;
//     }
//     return (*this);
// }

Warlock::Warlock(const std::string namee, const std::string titlee) : name(namee), title(titlee)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

const std::string Warlock::getName(void) const
{
    return (this->name);
}

const std::string Warlock::getTitle(void) const
{
    return (this->title);
}

void Warlock::setTitle(const std::string str)
{
    this->title = str;
}

void Warlock::introduce(void) const
{
    std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}
