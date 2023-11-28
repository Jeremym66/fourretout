/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:12:09 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/28 11:24:39 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void)
{}

TargetGenerator::~TargetGenerator(void)
{
    std::map<std::string, ATarget *>::iterator it = book.begin();
    while (it != book.end())
    {
        delete it->second;
        it++;
    }
    book.clear();
}

void TargetGenerator::learnTargetType(ATarget * target)
{
    if (target)
        book.insert(std::pair<std::string, ATarget *>(target->getType(), target->clone()));
}

void TargetGenerator::forgetTargetType(std::string const & name)
{
    std::map<std::string, ATarget *>::iterator it = book.find(name);
    if (it != book.end())
        delete it->second;
    book.erase(name);
}

ATarget * TargetGenerator::createTarget(std::string const & name)
{
    std::map<std::string, ATarget *>::iterator it = book.find(name);
    if (it != book.end())
        return book[name];
    return NULL;
}